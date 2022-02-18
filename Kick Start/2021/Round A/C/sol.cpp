//Rabbit House
//Solution: MaxHeap on box heights
#include <bits/stdc++.h>
using namespace std;

const int M = 4;
const int MN = 301;
const int dx[M] = {0,  0, 1, -1};
const int dy[M] = {1, -1, 0,  0};

int h[MN][MN];
int seen[MN][MN];

long long FixRabbitHouse(int tc) {
    int r, c;
    cin >> r >> c;
    int i, j;
    priority_queue<pair<int, pair<int, int>>> q;
    for (i=0; i<r; i++) {
        for (j=0; j<c; j++) {
            cin >> h[i][j];
            q.push({h[i][j], {i, j}});
        }
    }
    long long addings = 0;
    while (!q.empty()) {
        auto t = q.top();
        int height = t.first;
        int xx = t.second.first;
        int yy = t.second.second;
        q.pop();
        for (i=0; i<M; i++) {
            int x = xx + dx[i];
            int y = yy + dy[i];
            if (x<0 || x>=r || y<0 || y>=c) continue;
            if (seen[x][y]==tc) continue;
            int diff = abs(h[xx][yy] - h[x][y]);
            if (diff > 1) {
                addings += (diff - 1);
                h[x][y] += diff;
                h[x][y]--;
                q.push({h[x][y], {x, y}});
            }
            seen[x][y] = tc;
        }
    }
    
    return addings;
}

int main() {
    // freopen("sample.in", "r", stdin);
    int t; cin >> t;
    for (int tc=1; tc<=t; tc++) {
        cout << "Case #"<< tc << ": " << FixRabbitHouse(tc) << endl;
    }
    return 0;
}