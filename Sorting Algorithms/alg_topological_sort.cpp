#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

const int N = 100100;

int visited[N];
vector<int> graph[N];
stack<int> qu;

void topologicalSort(int u) {
    visited[u] = 1;
    for (int v : graph[u]) {
        if (!visited[v])
            topologicalSort(v);
    }
    qu.push(u);
}

int main() {

    int n, q;
    scanf("%d %d", &n, &q);

    int u, v;
    for (int i = 0; i < q; ++i) {
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
    }

    for (int i = 1; i <= n; ++i) {
        if (!visited[i])
            topologicalSort(i);
    }

    while (!qu.empty()) {
        int top = qu.top();
        qu.pop();
        printf("%d ", top);
    }


    return 0;
}
