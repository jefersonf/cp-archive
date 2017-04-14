#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
#include <fstream>
using namespace std;

const int N = 100010;

bool in_stack[N], seen[N];
int d[N], lw[N], g[N], t = 1, gid = 0;
vector <int> graph[N];
stack <int> S;

vector < vector<int> > components;

void dfs(int u) {
	d[u] = lw[u] = t++;
	in_stack[u] = true;
	S.push(u);
	for (int v : graph[u]) {
		if (!d[v]) {
			dfs(v);
			lw[u] = min(lw[u], lw[v]);
		} else if (in_stack[v]) {
			lw[u] = min(lw[u], d[v]);
		}
	}
	if (d[u] == lw[u]) {
		gid++;
		int x;
		vector <int> tmp;
		do {
			x = S.top(); S.pop();
			in_stack[x] = false;
			g[x] = gid;
			tmp.push_back(x);
		} while (x != u);
		components.push_back(tmp);
	}
}

void printPath(int u, bool f=false) {
	seen[u] = true;
	if (f) printf(" ");
	printf("%d", u);
	for (int v : graph[u])
		if (!seen[v] && g[v] == g[u]) {
			printPath(v, true);
		}
}

int main() {
	
	freopen("cycle.in", "rt", stdin);
	freopen("cycle.out", "wt", stdout);

	int n, m, i;
	scanf("%d %d", &n, &m);

	int u, v, k;
	bool self_loop = false;
	while (m--) {
		scanf("%d %d", &u, &v);
		graph[u].push_back(v);
		if (u == v) {
			self_loop = true;
			k = u;
		}
	}

	if (self_loop) {
		printf("YES\n%d %d\n", k, k);
		return 0;
	}

	for (i = 1; i <= n; ++i) if (!d[i]) { dfs(i); }

	for (i = 0; i < (int) components.size(); ++i) {
		if (components[i].size() > 1) {
			puts("YES");
			printPath(components[i][0]);
			printf("\n");
			return 0;
		}
	}

	puts("NO");
	return 0;
}