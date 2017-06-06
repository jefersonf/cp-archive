#include <iostream>
#include <fstream>
using namespace std;

typedef long long ll;

const int N = 100010;

ll h[N], L[N], R[N];

int main() {

  freopen("tc.in", "r", stdin);

  int i, T, n;
  cin >> T;

  while (T--) {
    cin >> n;
    ll Sum = 0LL;
    for (i = 0; i < n; ++i) {
      cin >> h[i];
      L[i] = R[i] = 0LL;
      if (i > 0) {
        Sum += h[i];
      } else {
        Sum = h[i];
      }
    }

    ll lf = 1LL, rt = 1LL;
    for (i = 0; i < n; ++i) {
      L[i] = min(h[i], lf);
      lf = L[i] + 1LL;
      R[n-i-1] = min(h[n-i-1], rt);
      rt = R[n-i-1] + 1LL;
    }

    ll mx = 0LL;
    for (i = 0; i < n; ++i) {
      mx = max(mx,  min(L[i], R[i]));
    }

    ll templ = ((mx*(mx + 1LL)) >> 1LL) + (((mx - 1LL)*mx) >> 1LL);
    cout << (Sum - templ) << '\n';
  }

  return 0;
}
