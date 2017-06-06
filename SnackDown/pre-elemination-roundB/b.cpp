#include <iostream>
#include <queue>
#include <fstream>
using namespace std;

const int N = 512;
const int dx[8] = {1,-1, 0, 0, 1,-1,-1, 1};
const int dy[8] = {0, 0, 1,-1, 1, 1,-1,-1};

typedef pair<int, int>  ii;
typedef pair<int, ii>  nod;

int n, m;
int g[N][N];
bool seen[N][N];

nod node(int l, int i, int j) {
  return make_pair(l, make_pair(i, j));
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
    int i, j, mx = 0;
    for (i = 0; i < n; ++i) {
      for (j = 0; j < m; ++j) {
        cin >> g[i][j];
        mx = max(mx, g[i][j]);
        seen[i][j] = false;
      }
    }

    queue <nod> Q;
    for (i = 0; i < n; ++i) {
      for (j = 0; j < m; ++j) {
        if (g[i][j] == mx) {
          Q.push( node(0, i, j) );
        }
      }
    }

    int layer = 0;
    while (!Q.empty())
    {
        nod t = Q.front();
        Q.pop();
        int r = t.second.first;
        int c = t.second.second;
        if (seen[r][c]) continue;
        layer = t.first;
        seen[r][c] = true;
        for (i = 0; i < 8; ++i) {
          int nr = r + dx[i];
          int nc = c + dy[i];
          if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
          if (!seen[nr][nc]) {
            Q.push( node(layer + 1, nr, nc) );
          }
        }
    }

    cout << layer << '\n';
  }

  return 0;
}
