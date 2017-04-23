#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

const int N = 10010;

bool seen[N];
int R, C, Q;
int tag, parent[N], d[N], low[N];
int rnk[N], p[N];
vector<int> graph[N];

void init() {
  tag = 1;
  for (int i = 0; i <= R; ++i) {
    graph[i].clear();
    seen[i] = false;
    parent[i] = 0;
    d[i] = 0;
    p[i] = i;
    rnk[i] = 0;
  }
}

int find_set(int x) {
  if (x == p[x]) return x;
  return p[x] = find_set(p[x]);
}

void connect(int i, int j) {
  int x = find_set(i), y = find_set(j);
  if (rnk[x] > rnk[y]) {
    p[y] = x;
  } else {
    p[x] = y;
    if (rnk[x] == rnk[y]) rnk[y]++;
  }
}

bool areTheyInTheSameSet(int u, int v) {
  return find_set(u) == find_set(v);
}

bool DFS(int u) {
  d[u] = low[u] = tag++;
  for (int v : graph[u]) {
    if (d[v] == 0) {
      parent[v] = u;
      DFS(v);
      if (low[v] > d[u]) connect(u, v);
      low[u] = min(low[u], low[v]);
    } else if (v != parent[u]) {
      low[u] = min(low[u], d[v]);
    }
  }
}

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  while (cin >> R >> C >> Q, R && C && Q)
  {
      init();
      int i, u, v;
      for (i = 0; i < C; ++i) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
      }

      for (i = 1; i <= R; ++i) {
        if (d[i] == 0) DFS(i);
      }

      while (Q--)
      {
        cin >> u >> v;
        areTheyInTheSameSet(u, v) ? cout << "Y\n" : cout << "N\n";
      }

      cout << "-\n";
  }

  return 0;
}
