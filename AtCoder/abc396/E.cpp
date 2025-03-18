#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a; i<=b; i++)
#define LEN(v) ((int)v.size())
typedef long long ll;

vector<bool> visited;
bool valid;

void dfs(int u, vector<int>& c, vector<ll>& a, vector<set<pair<int, ll>>>& g) {
    if (!valid) return;
    visited[u] = true;
    c.push_back(u);
    for (auto [v, w] : g[u]) {
        if (!visited[v]) {
            a[v] = a[u] ^ w;
            dfs(v, c, a, g);
        }
        if ((a[u] ^ a[v]) != w) {
            valid = false;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<set<pair<int, ll>>> g(n, set<pair<int, ll>>());

    int x, y;
    ll z;
    rep(i,0,m-1) {
        cin >> x >> y >> z;
        x--;
        y--;
        g[x].insert({y, z});
        g[y].insert({x, z});
    }

    visited.assign(n, false);
    vector<ll> a(n, 0);
    valid = true;
    rep(u,0,n-1) {
        if (visited[u]) continue;
        a[u] = 0;
        vector<int> comp;
        dfs(u, comp, a, g);
        if (!valid) {
            cout << -1 << "\n";
            return 0;
        }
        ll ones, p;
        ll mask = (1LL << 31) - 1;
        rep(j,0,30) {
            ones = 0;
            p = (ll)(1LL << j);
            for (int k : comp) {
                if (a[k] & p) ones++;
            }
            if (ones > LEN(comp) - ones) {
                for (int k : comp) {
                    p = (1LL << j);
                    if (a[k] & p) {
                        a[k] &= (mask ^ p);
                    } else {
                        a[k] |= p;
                    }

                }
            }
        }
    }

    for (auto x : a) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}
