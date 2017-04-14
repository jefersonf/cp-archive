#include <iostream>
#include <vector>
using namespace std;

const int N = 1000;

bool seen[N], exited[N];
vector <int> g[N];

bool dfs(int u) {
	seen[u] = true;
	for (int v : g[u]) {
		if ((seen[v] && !exited[v]) || (!seen[v] && dfs(v)))
			return true;
	}
	exited[u] = true;
	return false;
}

int main() {
	
	int n, q;
	cin >> n >> q;

	int u, v;
	while (q--) {
		cin >> u >> v;
		g[u].push_back(v);
	}

	puts(dfs(1) ? "YES" : "NO");
	return 0;
}