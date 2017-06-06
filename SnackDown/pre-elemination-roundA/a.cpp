#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 128;

int bit[N];

void add(int i) {
  while (i < N) {
    bit[i] += 1;
    i += (i&-i);
  }
}

int get(int i) {
  int s = 0;
  while (i > 0) {
    s += bit[i];
    i -= (i&-i);
  }
  return s;
}

int main() {

  freopen("tc.in", "r", stdin);

  int T;
  cin >> T;

  int i, n, m;
  while (T--) {
    cin >> n >> m;
    memset(bit, 0, sizeof(bit));
    int u, v;
    for (i = 0; i < m; ++i) {
      cin >> u >> v;
      add(u); add(v);
    }
    int r = n - get(n);
    (r%2==0) ? cout << "yes\n" : cout << "no\n";
  }

  return 0;
}
