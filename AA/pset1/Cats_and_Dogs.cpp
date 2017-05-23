#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int T;
  ll C, D, L;
  cin >> T;
  while (T--) {
    cin >> C >> D >> L;
    bool resp = false;
    if (L % 4LL == 0LL) {
      ll p = C + D - L/4LL;
      resp = (p >= 0) && p <= min(C, 2LL*D);
    }
    puts(resp ? "yes": "no");
  }
  return 0;
}
