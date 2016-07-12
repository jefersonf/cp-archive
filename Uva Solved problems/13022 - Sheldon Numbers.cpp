#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

typedef unsigned long long ll;

const ll N = 64;

set<ll> sn;
set<ll>::iterator it;

void init() {
    for (ll i = 1; i <= N; ++i) {
        for (ll j = 0; j <= N; ++j) {
            ll n = (1LL << i) - 1;
            ll p = n << j;
            sn.insert(p);
            for (ll k = 0; k <= N; ++k) {
                p = (p << i) | n;
                sn.insert(p);
                p <<= j;
                sn.insert(p);
            }
        }
    }
    sn.erase(0LL);
}

int main() {

    init();

    ll x, y, ans;
    while (scanf("%llu %llu", &x, &y) != EOF) {
        ans = 0LL;
        it = sn.begin();
        while (it != sn.end()) {
            if ((*it) >= x && (*it) <= y) ans++;
            ++it;
            if ((*it) > y) break;
        }
        printf("%llu\n", ans);
    }

    return 0;
}
