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
    vector<int> a;
    while (t--) {
        int n; cin >> n;
        a.resize(n);
        rep(i,0,n-1) a[i] = i+1;
        if (n & 1) {
            reverse(a.begin() + 1, a.end());
            for (auto x : a) { cout << x << " "; }
            cout << el;
        } else {
            cout << -1 << el;
        }
    }
    return 0;
}
