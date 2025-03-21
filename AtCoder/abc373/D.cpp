#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a; i<=(b); i++)
#define all(v) (v).begin(),(v).end()
#define len(v) (ll)((v).size())
#define el "\n"

vector<vector<pair<ll, ll>>> g;
vector<ll> a;
vector<bool> seen;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	g.assign(n, vector<pair<ll, ll>>());
	
	ll u, v, w;
	rep(i,0,m-1) {
		cin >> u >> v >> w;
		--u; --v;
		g[v].push_back({u, w});
		g[u].push_back({v, w});
	}
	
	a.assign(n, 0);
	seen.assign(n, false);
	rep(i,0,n-1) {
		if (seen[i]) continue;
		seen[i] = true;
		queue<ll> qu; qu.push(i);
		while (!qu.empty()) {
			u = qu.front(); qu.pop();
			for (auto [v, w] : g[u]) {
				if (!seen[v]) {
					seen[v] = true;
					a[v] = a[u] + w;
					qu.push(v);
				}
			}
		}
	}

	for (auto x : a) { cout << x << " "; }
	cout << el;

	return 0;
}
