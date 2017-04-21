#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;

const int N = 2000;

ll ugly[N];
set<ll> U;

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll next_m2 = 2LL;
  ll next_m3 = 3LL;
  ll next_m5 = 5LL;

  int i2 = 0, i3 = 0, i5 = 0;
  ugly[0] = 1LL;

  U.insert(1LL);
  for (int i = 1; i < N; ++i) {
    ll next = min(next_m2, min(next_m3, next_m5));
    ugly[i] = next;
    U.insert(next);
    if (next == next_m2) {
      i2++;
      next_m2 = ugly[i2] * 2LL;
    }
    if (next == next_m3) {
      i3++;
      next_m3 = ugly[i3] * 3LL;
    }
    if (next == next_m5) {
      i5++;
      next_m5 = ugly[i5] * 5LL;
    }
  }

  set<ll>::iterator it;
  int i = 1;
  for (it = U.begin(); it != U.end(); ++it) {
    ugly[i++] = (*it);
  }

  ll n;
  while (cin >> n, n) {
      cout << ugly[n] << '\n';
  }

  return 0;
}
