#include <iostream>
#include <fstream>
using namespace std;

#define INF 1000000000

const int N = 512;
const int dx[8] = {1,-1, 0, 0, 1,-1,-1, 1};
const int dy[8] = {0, 0, 1,-1, 1, 1,-1,-1};

int n, m, g[2][N][N];

int maxNeighbor(int p, int r, int c) {
  int ret = g[p][r][c];
  for (int i = 0; i < 8; ++i) {
    int x = r + dx[i], y = c + dy[i];
    if (x < 1 || x > n || y < 1 || y > m) continue;
    ret = max(ret, g[p][x][y]);
  }
  return ret;
}

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  freopen("tc.in", "r", stdin);

  int T;
  cin >> T;

  while (T--)
  {
    cin >> n >> m;
    int i, j, mx = 0, mn = INF;
    for (i = 0; i < n; ++i) {
      for (j = 0; j < m; ++j) {
        cin >> g[0][i][j];
        g[1][i][j] = g[0][i][j];
        mx = max(mx, g[0][i][j]);
        mn = min(mn, g[0][i][j]);
      }
    }

    int K = N, resp = 0, p = 1;
    while (K > 0 && mn != mx)
    {
      mn = INF;
      resp += 1;
      p = (p + 1) % 2;
      for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
          g[p][i][j] = g[1 - p][i][j];
          g[p][i][j] = maxNeighbor(1 - p, i, j);
          mn = min(mn, g[p][i][j]);
        }
      }
      K--;
    }

    cout << resp << '\n';
  }

  return 0;
}
