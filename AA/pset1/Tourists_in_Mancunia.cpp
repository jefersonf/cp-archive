#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

#define PB push_back

const int MN = 100100;

int a[MN], b[MN];
int in[MN], ou[MN];
vector <int> graph[MN];
set < pair<int, int> > P;

int main() {

  int i, N, E;
  cin >> N >> E;
  for (i = 0; i < E; ++i) {
    cin >> a[i] >> b[i];
    graph[a[i]].PB(b[i]);
    in[b[i]]++;
    ou[a[i]]++;
  }

  bool isItPossible = true;
  for (i = 1; i <= N; ++i) {
    if ((in[i] + ou[i])%2!=0 || (in[i]==0 && ou[i]==0)) {
      isItPossible = false;
    }
  }

  if (isItPossible) {
    for (i = 1; i <= N; ++i)
    {
      int u = a[i];
      if (in[u] == ou[u]) continue;
      for (int v : graph[u])
      {
        if (in[v] == ou[v]) continue;
        if (in[u] < ou[u]) {
          in[u]++; ou[u]--;
          in[v]--; ou[v]++;
          if (in[u] == ou[u] && in[u] && in[v] == ou[v] && in[v]) {
            P.insert({u, v});
          } else {
            in[u]--; ou[u]++;
            in[v]++; ou[v]--;
          }
        } else {
          in[u]--; ou[u]++;
          in[v]++; ou[v]--;
          if (in[u] == ou[u] && in[u] && in[v] == ou[v] && in[v]) {
            P.insert({u, v});
          } else {
            in[u]++; ou[u]--;
            in[v]--; ou[v]++;
          }
        }
      }
    }

    for (i = 1; isItPossible && i <= N; ++i) {
      if (in[i] != ou[i] || in[i]==0 || ou[i]==0)
        isItPossible = false;
    }
  }

  if (isItPossible) {
    cout << "YES\n";
    for (i = 0; i < E; ++i) {
      if (P.count({a[i], b[i]})) {
        int t = a[i];
        a[i] = b[i];
        b[i] = t;
      }
      cout << a[i] <<" "<< b[i] << '\n';
    }
  } else {
    cout << "NO\n";
  }

  return 0;
}
