#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

const int N = 1010;

int scc_cnt = 0, tag = 0;
bool inStack[N];
int visited[N], lowlnk[N], dp[N];
int component_id[N], component_cnt[N];
vector<int> graph[N], dag[N];
stack<int> Stack;

void tarjanDFS(int u) {
    visited[u] = lowlnk[u] = ++tag;
    Stack.push(u);
    inStack[u] = true;
    for (auto v : graph[u]) {
        if (!visited[v]) {
            tarjanDFS(v);
            lowlnk[u] = min(lowlnk[u], lowlnk[v]);
        } else if (inStack[v]) {
            lowlnk[u] = min(lowlnk[u], lowlnk[v]);
        }
    }

    if (visited[u] == lowlnk[u]) {
        int top;
        scc_cnt++;
        dp[scc_cnt] = -1;
        do {
            top = Stack.top(); Stack.pop();
            inStack[top] = false;
            component_cnt[scc_cnt]++;
            component_id[top] = scc_cnt;
        } while (top != u);
    }
}

int DFS(int u) {
    if (dp[u] != -1)
        return dp[u];
    int ret = 0;
    for (auto v : dag[u])
        ret = max(ret, DFS(v));
    return dp[u] = ret + component_cnt[u];
}

int main() {

    int T, n, q;
    scanf("%d", &T);

    while (T--) {

        scanf("%d %d", &n, &q);

        int u, v;
        for (int i = 0; i < q; ++i) {
            scanf("%d %d", &u, &v);
            graph[u].push_back(v);
        }

        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) tarjanDFS(i);
        }

        int x, y;
        for (int i = 1; i <= n; ++i) {
            x = component_id[i];
            for (int j = 0; j < graph[i].size(); ++j) {
                y = component_id[graph[i][j]];
                if (x != y && !inStack[y]) {
                    Stack.push(y);
                    inStack[y] = true;
                    dag[x].push_back(y);
                }
            }
            while (!Stack.empty()) {
                inStack[Stack.top()] = false;
                Stack.pop();
            }
        }

        int ans = 0;
        for (int i = 1; i <= scc_cnt; ++i) {
            ans = max(ans, DFS(i));
        }

        printf("%d\n", ans);

        scc_cnt = tag = 0;
        for (int i = 1; i <= n; ++i) {
            graph[i].clear();
            dag[i].clear();
            visited[i] = lowlnk[i] = 0;
            component_id[i] = component_cnt[i] = 0;
            inStack[i] = false;
        }
    }

    return 0;
}
