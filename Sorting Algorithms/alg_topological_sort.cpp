
/* Overall complexity: O(V + E)
 * where V and E are the number of vertices and edges
 * on the graph, respectively
 */

const int MaxN = 100100;

int visited[MaxN], lowlink[MaxN], inqu[MaxN], tag = 0;
vector<int> adj[MaxN];
queue<int> qu;

void topological_sort(int u) {
    visited[u] = lowlink[u] = ++tag;
    qu.push(u);
    inqu[u] = 1;
    for (int v : adj[u]) {
        if (!visited[v]) {
            topological_sort(v);
            lowlink[u] = min(lowlink[u], lowlink[v]);
        } else if (inqu[v]) {
            lowlink[u] = min(lowlink[u], lowlink[v]);
        }
    }
}
