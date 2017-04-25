#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

const int N = 1010;

bool seen[N];
int indeg[N];
vi graph[N];
vector<vi> components;

void DFS(int u) {
  seen[u] = true;
  components.back().push_back(u);
  for (int v : graph[u]) {
    if (!seen[v]) {
      DFS(v);
    }
  }
}

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int i, j, n, m, R, E;
  cin >> n >> m >> R >> E;

  int a, b;
  for (i = 0; i < m; ++i) {
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
    indeg[a]++;
    indeg[b]++;
  }

  for (i = 1; i <= n; ++i) {
    if (!seen[i]) {
      components.push_back(vector<int>());
      DFS(i);
    }
  }

  int min_cost = 0;
  for (i = 0; i < (int) components.size(); ++i) {
    int nv = components[i].size();
    int ne = 0;
    for (j = 0; nv > 1 && j < nv; ++j) {
      ne += (nv - indeg[components[i][j]] - 1);
    }
    ne /= 2;
    min_cost += min(ne*R, nv*E);
  }

  cout << min_cost << '\n';
  return 0;
}
