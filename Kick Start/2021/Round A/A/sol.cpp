//K-Goodness String
//Solution: absolute difference
#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("sample.in", "r", stdin);
    int T, tc;
    cin >> T;
    for (tc=1; tc<=T; tc++) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int g = 0;
        for (int i=0; i<n/2; i++) {
            g += (s[i] != s[n - i - 1]);
        }
        cout << "Case #" << tc <<  ": " << abs(k - g) << endl; 
    }
    
    return 0;
}