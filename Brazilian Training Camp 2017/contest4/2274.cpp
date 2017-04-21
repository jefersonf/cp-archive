#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

bool is_prime(ll n) {
  if (n <= 1LL) return false;
  for (ll i = 2LL; i <= (ll)(sqrt(n)); i += 1LL) {
    if (n % i == 0LL) return false;
  }
  return true;
}

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t-- > 0) {
      ll n;
      cin >> n;
      while (!is_prime(n)) n++;
      cout << n << '\n';
  }

  return 0;
}
