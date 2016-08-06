#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define range(i,n) for(int i=0; i<n; ++i)
#define add push_back

const int MaxN = 100010;

bool visited[MaxN], articulation_vertex[MaxN];
int d[MaxN], low[MaxN], tm;
vector <int> graph[MaxN];

void DFS(int u, int parent) {
	d[u] = low[u] = tm++;
	visited[u] = true;
	int nchild = 0;
	bool any = false;
	for (int v : graph[u]) {
		if (!visited[v]) {
			DFS(v, u);
			nchild++;
			if (low[v] >= d[u]) any = true;
			if (low[v] > d[u]) { printf(" Edge (%d, %d) is a bridge\n", u, v); }
			low[u] = min(low[u], low[v]);
		} else if (v != parent) {
			low[u] = min(low[u], d[v]);
		}
	}

	if (u == parent && nchild > 1)
		articulation_vertex[u] = true;
	else if (u != parent && any)
		articulation_vertex[u] = true;
}

void reset(int n) {
	tm = 0;
	range(i, n) {
		visited[i] = articulation_vertex[i] = false;
		graph[i].clear();
		d[i] = low[i] = 0;
	}
}
void articulationPointAndBridge(int n) {
	range(u, n) if (!visited[u]) DFS(u, u);
	printf("Articulation Points\n");
	range(i, n) if (articulation_vertex[i]) printf("%d ", i); printf("\n");
	reset(n);
}