#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a; i<=(b); i++)
#define all(v) (v).begin(),(v).end()
#define len(v) (ll)((v).size())
#define el "\n"

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n; cin >> n;
	vector<ll> a(n), b(n);
	rep(i,0,n-1) cin >> a[i];
	rep(i,0,n-1) cin >> b[i];
	sort(all(a)); sort(all(b));
	cout << max(a[n-1], b[n-1]) << el;
	return 0;
}
