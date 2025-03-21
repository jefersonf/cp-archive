#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a; i<=(b); i++)
#define all(v) (v).begin(),(v).end()
#define len(v) (ll)((v).size())
#define el "\n"

vector<ll> a;

bool cmp(int i, int j) {
    return a[i] < a[j];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    freopen("in.txt", "r", stdin);

	ll n, m, k;
    cin >> n >> m >> k;
    a.assign(n, 0);
    vector<int> pos(n);
    ll s = 0;
    rep(i,0,n-1) cin >> a[i], s += a[i], pos[i] = i;
    sort(pos.begin(), pos.end(), cmp);
    vector<ll> b(n);
    rep(i,0,n-1) b[i] = a[pos[i]];
    for (auto x : b) { cout << x <<" "; } cout << el;
    ll r = k - s;
    cout << "r: " << r << el;
    vector<ll> c(n, -1);
    rep(i,0,n-1) {
        ll v = a[i];
        cout << "\na["<<i<<"] = " << v << el;
        ll lo = 0, hi = r;
        while (lo <= hi) {
            ll x = (lo + hi)/2;
            cout << "x: " << x <<" -> v+x: " << v+x;
            ll p = (lower_bound(b.begin(), b.end(), v+x) - b.begin());
            ll q = n - p;
            cout << ", more votes: " << q << el;
            if (q >= m && p < n-1) {
                lo = x+1;
            } else {
                hi = x-1;
            }
        }
        if (lo <= r) c[i] = lo;
    }

    for (auto x : c) { cout << x << " "; }
    cout << el;
	return 0;
}
