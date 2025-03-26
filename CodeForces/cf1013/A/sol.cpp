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
        int n; cin >> n;
        map<int, int> d;
        int a; bool found = false;
        rep(i,0,n-1) {
            cin >> a;
            d[a]++;
            if (!found && d[0]>=3 && d[1]>=1 && d[3]>=1 && d[2]>=2 && d[5]>=1) {
                cout << (i+1) << el;
                found = true;
            }
        }
        if (!found || n < 8) {
            cout << 0 << el;
        }
    }
    return 0;
}
