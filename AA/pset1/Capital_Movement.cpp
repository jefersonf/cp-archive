#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define L(x) (2*x)
#define R(x) (2*x+1)
#define INF 1000000007

const int MN = 50010;

struct nod {
  int pos, value;
  nod() {}
  nod(int i, int p) : pos(i), value(p) {}
  bool operator <(const nod& other) const {
    return value < other.value;
  }
};

int P[MN];
nod tree[4*MN];
vector <int> graph[MN];

nod fun(int i) {
  return max(tree[L(i)], tree[R(i)]);
}

void build(int i, int l, int r) {
    if (l == r) {
      tree[i] = nod(l, 0);
      graph[l].clear();
    } else {
      int m = (l+r)/2;
      build(L(i), l, m);
      build(R(i), m+1, r);
    }
}

void upd(int i, int l, int r, int p, int v) {
  if (l == r) {
    tree[i] = nod(l, v);
  } else {
    int m = (l+r)/2;
    if (p <= m)
      upd(L(i), l, m, p, v);
    else
      upd(R(i), m+1, r, p, v);
    tree[i] = fun(i);
  }
}

nod getMax(int k, int l, int r, int i, int j) {
  if (j < l || i > r) return nod(0, 0);
  if (i >= l && j <= r) return tree[k];
  int m = (l + r)/2;
  nod jeff = getMax(L(k), l, m, i, j);
  nod will = getMax(R(k), m+1, r, i, j);
  return max(jeff, will);
}

int main() {

  int T;
  cin >> T;

  int i, N;
  while (T--) {
    cin >> N;
    build(1, 1, N);
    for (i = 1; i <= N; ++i) {
      cin >> P[i];
      upd(1, 1, N, i, P[i]);
    }
    int u, v;
    for (int i = 0; i < N-1; ++i) {
      cin >> u >> v;
      graph[u].PB(v);
      graph[v].PB(u);
    }

    for (int i = 1; i <= N; ++i) {
      upd(1, 1, N, i, 0);
      for (int c : graph[i]) {
        upd(1, 1, N, c, 0);
      }
      int resp = getMax(1, 1, N, 1, N).pos;
      if (graph[i].size() == N-1) resp = 0;
      cout << resp << " ";
      upd(1, 1, N, i, P[i]);
      for (int c : graph[i]) {
        upd(1, 1, N, c, P[c]);
      }
    }
    cout << '\n';
  }

  return 0;
}
