#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int N = 100100;

bool visited[N];
vector <int> graph[N];
vector <int> ans;

void DFS(int u) {
    visited[u] = true;
    for (int v : graph[u])
        if (!visited[v]) DFS(v);
    ans.push(u);
}

void topoSort(int n) {
    memset(visited, false, sizeof(bool) * (n + 1));
    ans.clear();
    for (int i = 0; i < n; ++i)
        if (!visited[i]) DFS(i);
    reverse(ans.begin(), ans.end());
}