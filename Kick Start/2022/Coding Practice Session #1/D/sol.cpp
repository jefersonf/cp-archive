//Hex
//Solution: Implementation + Vertex Cutting
#include <bits/stdc++.h>
using namespace std;

const int M = 6;
const char BLUE  = 'B';
const char RED   = 'R';

int dx[M] = {1,-1, 0, 0,  1, -1};
int dy[M] = {0, 0, 1,-1, -1,  1};

bool hasWinningPath(vector<string>& board, char color) {
    int size = board.size();
    vector<vector<bool>> seen(size, vector<bool>(size, false));
    queue<pair<int, int>> q;
    int i, j;
    for (i=0; i<size; i++) {
        if (color == BLUE) {
            if (board[i][0] == BLUE)
                q.push({i, 0}), seen[i][0] = true;
        } else if (color == RED) {
            if (board[0][i] == RED)
                q.push({0, i}), seen[0][i] = true;
        }
    }

    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        for (j=0; j<M; j++) {
            int row = t.first + dy[j];
            int col = t.second + dx[j];
            if (row<0 || row>=size|| col<0 || col>=size) continue;
            if (seen[row][col] || board[row][col] != color) continue;
            seen[row][col] = true;
            q.push({row, col});
        }
    }

    for (i=0; i<size; i++) {
        if (seen[i][size-1] && color == BLUE) return true;
        if (seen[size-1][i] && color == RED) return true;
    }
    return false;
}

bool hasCuttingStone(vector<string>& board, char color) {
    int size = board.size();
    int i, j;
    for (i=0; i<size; i++) {
        for (j=0; j<size; j++) {
            if (board[i][j] == color) {
                board[i][j] = '.';
                bool stillHaveWinningPath = hasWinningPath(board, color);
                board[i][j] = color;

                if (!stillHaveWinningPath) {
                    return true;
                }
            }
        }
    }
    return false;
}

string FindBoardStatus(int size) {
    vector<string> board(size);
    int i, j, n = size;
    int bStones = 0, rStones = 0;
    for (i=0; i<n; i++) {
        cin >> board[i];
        for (j=0; j<n; j++) {
            if (board[i][j] == BLUE)
                bStones += 1;
            else if (board[i][j] == RED)
                rStones += 1;
        }   
    }

    bool hasBlueWinningPath = hasWinningPath(board, BLUE);
    bool hasBlueCuttingStone = hasCuttingStone(board, BLUE);
    bool hasRedWinningPath = hasWinningPath(board, RED);
    bool hasRedCuttingStone = hasCuttingStone(board, RED);

    if (abs(bStones - rStones) > 1 
        || (hasBlueWinningPath && (!hasBlueCuttingStone || rStones > bStones))
        || (hasRedWinningPath && (!hasRedCuttingStone || bStones > rStones))) {
        return "Impossible";
    } else if (hasBlueWinningPath) {
        return "Blue wins";
    } else if (hasRedWinningPath) {
        return "Red wins";
    }
    return "Nobody wins";
}

int main() {
    int T, tc; cin >> T;
    for (tc=1; tc<=T; tc++) {
        int n;
        cin >> n;
        cout << "Case #" << tc << ": " << FindBoardStatus(n) << endl;
    }
    return 0;
}
