#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 200010;

int n;
int h[N], sorted[N], id[N], LEFT[N], RIGHT[N];

struct BIT {
  int t[N];

  BIT() { memset(t, 0, sizeof t); }

  void update(int i, int v) {
    while (i < N) {
      t[i] = max(t[i], v);
      i += (i&(-i));
    }

  }
  int query(int i) {
    int mx = 0;
    while (i > 0) {
      mx = max(mx, t[i]);
      i -= (i&(-i));
    }
    return mx;
  }

};

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int i, Z;
  cin >> Z;

  while (Z--) {
    cin >> n;
    for (i = 1; i <= n; ++i) {
      cin >> h[i];
      sorted[i] = h[i];
    }

    sort(sorted + 1, sorted + n + 1);
    for (i = 1; i <= n; ++i) {
      id[i] = lower_bound(sorted, sorted + n, h[i]) - sorted;
    }

    RIGHT[n] = 1;
    for (i = n-1; i > 0; --i) {
      RIGHT[i] = 1;
      if (id[i] < id[i+1])
        RIGHT[i] += RIGHT[i+1];
    }

    BIT tree;
    int ans = 0;

    for(i = 1; i <= n; ++i) {
      LEFT[i] = 1;
      if (id[i] > id[i-1])
        LEFT[i] += LEFT[i-1];

      tree.update(id[i], LEFT[i]);
      int sum = tree.query(id[i] - 1) + RIGHT[i];
      if (sum > ans) ans = sum;
    }

    cout << ans << '\n';
  }

  return 0;
}
