#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define pb push_back
#define rep(i,a,b) for(int i=a; i<=(b); i++)
#define all(v) v.begin(),v.end()
#define el "\n"

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    freopen("in.txt", "r", stdin);

    int t; cin >> t;
    while (t--) {
        ll n, m, k; cin >> n >> m >> k;
        ll i = 0, j = min(m, k);
        while (i != j) {
            ll benchsize = (i + j)/2;
            if (n*m - n*(m/(benchsize+1)) >= k) {
                j = benchsize;
            } else {
                i = benchsize + 1;
            }
        }
        cout << i << el;
    }
    return 0;
}
