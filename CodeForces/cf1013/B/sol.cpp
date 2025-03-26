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
        int n, x, a; cin >> n >> x;
        priority_queue<int> pq;
        rep(i,0,n-1) {
            cin >> a;
            pq.push(a);
        }
        int teams = 0;
        int l = 1;
        while (!pq.empty()) {
            int t = pq.top(); pq.pop();
            if (l*t >= x) {
                teams++;
                l = 1;
            } else {
                l++;
            }
        }
        cout << teams << el;
    }
    return 0;
}
