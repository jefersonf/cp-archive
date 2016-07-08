#include <bits/stdc++.h>
using namespace std;

const int MaxN = 100100;

int nV, nE, top, scc_cnt = 0, tag = 0;
int visited[MaxN], lowlnk[MaxN];
bool inHeap[MaxN];
vector <int> graph[MaxN];
stack <int> heap;

void tarjanDFS(int u) {
	visited[u] = lowlnk[u] = ++tag;
	heap.push(u);
	inHeap[u] = true;
	for (int i = 0; i < graph[u].size(); ++i) {
		int v = graph[u][i];
		if (!visited[v]) {
			tarjanDFS(v);
			lowlnk[u] = min(lowlnk[u], lowlnk[v]);
		} else if (inHeap[v]) {
			lowlnk[u] = min(lowlnk[u], lowlnk[v]);
		}
	}

	if (visited[u] == lowlnk[u]) {
		scc_cnt++;
		int top;
		do {
			top = heap.top();
			heap.pop();
			inHeap[top] = false;
		} while (top != u);
	}
}	
