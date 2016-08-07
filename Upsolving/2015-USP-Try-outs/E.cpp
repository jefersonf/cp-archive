#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

#define fi first
#define sc second
#define mp make_pair

typedef pair<int, int> ii;

const int dx[4] = {0,1, 0,-1};
const int dy[4] = {1,0,-1, 0};

const int N = 1010;

char t[N][N];
bool seen[N][N];
int f[N][N], g[N][N];

int main() {

	int T, n, m, i, j; scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &m);

		memset(seen, false, sizeof seen);
		memset(f, -1, sizeof f);

		ii E, S;
		queue <ii> qu;
		for (i = 0; i < n; ++i) {
			scanf("%s", t[i]);
			for (j = 0; j < m; ++j) {
				if (t[i][j] == 'S') S = mp(i, j);
				else if (t[i][j] == 'E') E = mp(i, j);
				else if (t[i][j] == 'F') {
					qu.push(mp(i, j));
					f[i][j] = 0;
				}
			}
		}

		while (!qu.empty()) {
			ii p = qu.front(); qu.pop();
			if (!seen[p.fi][p.sc]) {
				seen[p.fi][p.sc] = true;
				if (p.fi == E.fi && p.sc == E.sc) break;
				for (i = 0; i < 4; ++i) {
					int x = p.fi + dx[i], y = p.sc + dy[i];
					if (x<0 || x>=n || y<0 || y>=m) continue;
					if (t[x][y] == '#' || seen[x][y]) continue;
					if (f[x][y] > 0) {
						f[x][y] = min(f[x][y], 1 + f[p.fi][p.sc]);
					} else if (f[i][j] == -1) {
						f[x][y] = 1 + f[p.fi][p.sc];
					}
					qu.push(mp(x, y));
				}
			}
		}

		while (!qu.empty()) qu.pop();
		
		memset(seen, false, sizeof seen);
		memset(g, -1, sizeof g);

		qu.push(S);

		g[S.fi][S.sc] = 0;
		while (!qu.empty()) {
			ii p = qu.front(); qu.pop();
			if (!seen[p.fi][p.sc]) {
				seen[p.fi][p.sc] = true;
				if (p.fi == E.fi && p.sc == E.sc) break;
				for (i = 0; i < 4; ++i) {
					int x = p.fi + dx[i], y = p.sc + dy[i];
					if (x<0 || x >=n || y<0 || y>=m) continue;
					if (t[x][y] == '#' || t[x][y] == 'F' || seen[x][y]) continue;
					if (f[x][y] > 0 && f[x][y] <= 1 + g[p.fi][p.sc]) continue;

					g[x][y] = 1 + g[p.fi][p.sc];
					qu.push(mp(x, y));
				}
			}
		}

		printf("%c\n", (g[E.fi][E.sc] != -1) ? 'Y' : 'N');
	}

	return 0;
}

/*
1
4 4
S..F
....
...F
E...

*/