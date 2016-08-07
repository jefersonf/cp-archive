#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

#define range(i, n) for(int i=0; i<n; ++i)
#define pb push_back

const int N = 110;

bool vis[N];
int d[N], low[N], critical[N], tm;
vector <int> g[N];

void dfs(int u, int p) {
	d[u] = low[u] = tm++;
	vis[u] = true;
	int nc = 0; bool any = false;
	for (int v : g[u]) {
		if (!vis[v]) {
			dfs(v, u);
                        nc++;
			if (low[v] >= d[u]) any = true;
                        low[u] = min(low[u], low[v]);
		} else if (v != p) {
			low[u] = min(low[u], d[v]);
		}
	}

	if (u == p && nc > 1) {
		critical[u] = 1;
	} else if (u != p && any) {
		critical[u] = 1;
	}
}

void reset(int n) {
    tm = 0;
    range(i, n+1) {
    	vis[i] = false;
	g[i].clear();
	d[i] = low[i] = critical[i] = 0;
    }
}

int main() {
	
	int n, m, u, v;
	while (scanf("%d", &n), n) {

		reset(n);
		while (scanf("%d", &u), u) {
			while (scanf("%d", &v) > 0) {
				g[u].pb(v);
				g[v].pb(u);
				if (getchar() == '\n') break;
			}
		}

        range(i, n) if (!vis[i+1]) dfs(i+1, i+1);
		
        int ans = 0;
        range(i, n) ans += critical[i+1];
        printf("%d\n", ans);
	}

	return 0;
}
