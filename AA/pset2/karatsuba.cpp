#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

typedef long long ll;

const ll B = 10LL;

ll len(ll a) {
	ll m = 0;
	while (a > 0) { a /= B; m++; }
	return m;
}

ll pwr(ll a, ll n) {
	if (n == 0LL) return 1LL;
	if (n & 1LL)
		return a * pwr(a, n - 1);
	ll y = pwr(a, n >> 1);
	return y*y;
}

ll karatsuba(ll a, ll b) {
  if (a < 10LL || b < 10LL)
    return a*b;
  ll m = max(len(a), len(b)) >> 1;
  ll t = pwr(B, m);
  ll x1 = a/t, x0 = a%t;
  ll y1 = b/t, y0 = b%t;
  ll z2 = karatsuba(x1, y1);
  ll z1 = karatsuba((x0 + x1), (y0 + y1));
  ll z0 = karatsuba(x0, y0);
  return z2*pwr(B, 2*m) + (z1-z2-z0)*pwr(B, m) + z0;
}

int main() {

  return 0;
}
