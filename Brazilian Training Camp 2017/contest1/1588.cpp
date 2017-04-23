#include <iostream>
#include <queue>
#include <set>
#include <cstring>
using namespace std;

const int N = 10010;

bool seen[N];
int parent[N];
set <int> graph[N];

void init(int n) {
  for (int i = 0; i <= n; ++i) {
    graph[i].clear();
    parent[i] = i;
  }
}

bool findAnotherPath(int u, int v, int n) {
  memset(seen, false, sizeof(bool)*(n+1));
  queue <int> qu;
  qu.push(u);
  while (!qu.empty()) {
    int w = qu.front();
    qu.pop();
    if (seen[w]) continue;
    seen[w] = true;
    if (w == v) return true;
    for (int h : graph[w]) {
      if (!seen[h]) qu.push(h);
    }
  }
  return false;
}

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int i, R, C, Q;
  while (cin >> R >> C >> Q) {
      if (R==0 && C==0 && Q==0) break;
      init(R);
      int u, v;
      for (i = 0; i < C; ++i) {
        cin >> u >> v;
        graph[u].insert(v);
        graph[v].insert(u);
      }

      while (Q--)
      {
        cin >> u >> v;
        memset(seen, false, sizeof(bool)*(R+1));
        queue <int> qu;
        qu.push(u);
        bool has_path = false;
        while (!qu.empty())
        {
          int s = qu.front();
          qu.pop();
          if (seen[s]) continue;
          seen[s] = true;
          if (s == v) {
            has_path = true;
            break;
          }
          for (int w : graph[s]) {
            if (!seen[w]) {
              qu.push(w);
              parent[w] = s;
            }
          }
        }

        if (has_path) {
          int _v = v;
          bool has_another_path = false;
          while (v != u) {
            if (graph[v].size() > 1) {
              graph[parent[v]].erase(v);
              graph[v].erase(parent[v]);
              has_another_path = findAnotherPath(u, _v, R);
              graph[parent[v]].insert(v);
              graph[v].insert(parent[v]);
              if (has_another_path) break;
            }
            v = parent[v];
          }
          has_another_path ? cout << "N" : cout << "Y";
        } else {
          cout << "N";
        }
        cout << '\n';
      }
      cout << "-\n";
  }

  return 0;
}
