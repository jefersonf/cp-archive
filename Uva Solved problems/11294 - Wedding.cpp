#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

const int N = 1 << 10;

#define Not(p) (p^1)

bool visited[N];
vector <int> graph[N];
stack <int> S;

bool DFS(int u) {

	if (visited[Not(u)]) return false;
	if (visited[u]) return true;
	
	visited[u] = true;
	S.push(u);

	for (int v : graph[u])
		if (!DFS(v)) return false;
	return true;
}

void reset(int n) {
	memset(visited, false, sizeof visited);
	visited[1] = true;
	for (int i = 0; i < N; ++i)
		graph[i].clear();
}

int main() {

	int n, a;
	while (scanf("%d %d", &n, &a) == 2, n || a) {

		reset();
		int u, v; char c1, c2;
		for (int i = 0; i < a; ++i) {
			scanf("%d%c %d%c", &u, &c1, &v, &c2);

			u = (c1 == 'w') ? 2*u + 1 : 2*u;
			v = (c2 == 'w') ? 2*v + 1 : 2*v;

			graph[Not(u)].push_back(v);
			graph[Not(v)].push_back(u);
		}

		memset(visited, false, sizeof visited);

		bool ans = true;
		for (int i = 0; ans && i < 2*n; i += 2)  {
			if (!visited[i] && !visited[i+1]) {
				if (!DFS(i)) {
					while (!S.empty()) {
						visited[S.top()] = false;
						S.pop();
					}
					if (!DFS(i+1)) ans = false;
				}
			}
		}

		if (ans) {
			for (int i = 1; i < n; ++i) {
				if (i-1) printf(" ");
				printf("%d%c", i, visited[2*i] ? 'h' : 'w');
			}
			printf("\n");
		} else
			printf("bad luck\n");
	}

	return 0;
}

/*

10 6
3h 7h
5w 3w
7h 6w
8w 3w
7h 3w
2w 5h

*/