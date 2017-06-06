#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;

const int N = 512;

int tid = 1;
int seen[2][N];
char snake[2][N];

int go(int x, int y, int sum, int n) {
  if (snake[x][y] != '#') return sum;
  seen[x][y] = tid;
  if (snake[1 - x][y] == '#' && seen[1 - x][y] != tid)
    return go(1 - x, y, sum + 1, n);
  else if (y + 1 < n && snake[x][y+1]=='#' && seen[x][y+1] != tid)
    return go(x, y + 1, sum + 1, n);
  return sum;
}

int main() {

  freopen("tc.in", "r", stdin);

  int i, T;
  cin >> T;

  while (T--)
  {
    int n;
    cin >> n;
    for (i = 0; i < 2; ++i) {
      scanf("%s", snake[i]);
    }

    bool segment_check = false;
    bool found = false;
    int m = n - 1;
    int cnt = 0;
    int x = -1, y = -1;
    while (m >= 0 && (snake[0][m]=='.' && snake[1][m]=='.')) m--;
    for (i = 0; i <= m; ++i) {
      if (snake[0][i]=='#' || snake[1][i]=='#') {
        found = true;
        if (x < 0) {
          x = (snake[0][i]=='#') ? 0 : 1;
          y = i;
        }
      } else {
        segment_check = segment_check || found;
      }
      cnt += (snake[0][i]=='#');
      cnt += (snake[1][i]=='#');
    }

    if (segment_check) {
      cout << "no\n";
    } else if (cnt > 0) {
      int len1 = go(x, y, 1, n);
      int len2 = len1;
      if (snake[1 - x][y]=='#') {
        tid++;
        len2 = go(1 - x, y, 1, n);
      }
      if (len1 != cnt && len2 != cnt) {
        cout << "no\n";
      } else {
        cout << "yes\n";
      }
    } else {
    	cout << "no\n";
    }

    tid++;
  }

  return 0;
}
