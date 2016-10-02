#include <bits/stdc++.h>
using namespace std;

const int MaxN = 100100;

int nV, nE, scc_cnt = 0, tag = 0;
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
			lowlnk[u] = min(lowlnk[u], visited[v]);
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

int main() {
	
	scanf("%d %d", &nV, &nE);

	int u, v;
	for (int i = 0; i < nE; ++i) {
		scanf("%d %d", &u, &v);
		graph[u].push_back(v);
	}

	for (int i = 1; i <= nV; ++i) {
		if (!visited[i])
			tarjanDFS(i);
	}

	printf("scc: %d\n", scc_cnt);

	for (int i = 0; i <= 2*nV; ++i) {
		printf("%d ", lowlnk[i]);
	} printf("\n");

	for (int i = 0; i <= 2*nV; ++i) {
		printf("%d ", visited[i]);
	} printf("\n");

	return 0;
}
