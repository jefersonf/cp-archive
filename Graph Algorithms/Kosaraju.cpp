#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100100;

bool visited[N];
vector <int> graph[N], graphTranspose[N];
vector <int> order, component;

void DFS(int u) {
	visited[u] = true;
	for (int v : graph[u])
		if (!visited[v])
			DFS(v);
	order.push_back(u);
}

void DFSt(int u) {
	visited[u] = true;
	component.push_back(u);
	for (int v : graphTranspose[u])
		if (!visited[v])
			DFSt(v);
}

int main() {
	
	int nV;
	scanf("%d", &nV);

	int u, v;
	for (int i = 0; i < nV; ++i) {
		scanf("%d %d", &u, &v);
		graph[u].push_back(v);
		graphTranspose[v].push_back(u);
	}

	memset(visited, false, sizeof(bool) * (nV+1));
	for (int i = 0; i < nV; ++i)
		if (!visited[i]) DFS(i);

	memset(visited, false, sizeof(bool) * (nV+1));
	for (int i = nV - 1; i >= 0; --i) {
		if (!visited[i]) {
			DFSt(i);
			// get the j-th component
			// do something with the j-th component
			component.clear();
		}
	}

	return 0;
} 