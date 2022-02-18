// Milk Tea
// Solution: Hash table + MinHeap over possible complaints
#include <bits/stdc++.h>
using namespace std;
int main() {
    int T, tc; cin >> T;
    for (tc=1; tc<=T; tc++) {
        int n, m, p;
        cin >> n >> m >> p;
        vector<int> u(p, 0), z(p, 0);
        int i, j;
        for (i=0; i<n; i++) {
            string s;
            cin >> s;
            for (j=0; j<p; j++) {
                if (s[j]=='1') u[j]++;
                else z[j]++;
            }
        }
        set<__int128_t> fo;
        for (i=0; i<m; i++) {
            string s;
            cin >> s;
            __int128_t w = (__int128_t)0;
            for (j=0; j<p; j++) {
                if (s[p-j-1]=='1') w |= ((__int128_t)1 << (__int128_t)j);
            }
            fo.insert(w);
        }

        int c = 0;
        __int128_t st = (__int128_t)0;
        for (i=0; i<p; i++) {
            if (z[i] > u[i]) {
                c += u[i];
            } else {
                st |= ((__int128_t)1 << (__int128_t)(p-i-1)); 
                c += z[i];
            }
        }

        set<__int128_t> seen;
        priority_queue<pair<int, __int128_t>> pq;
        seen.insert(st);
        pq.push({-c, st});
        while (!pq.empty()) {
            auto t = pq.top();
            pq.pop();
            __int128_t opt = t.second;
            int complaints = -t.first;
            if (fo.find(opt) == fo.end()) {
                cout << "Case #" << tc << ": " << complaints << endl;
                break;
            }
            for (i=0; i<p; i++) {
                __int128_t cpy = opt;
                int comp = complaints;
                __int128_t pos = (__int128_t)1 << (__int128_t)(p-i-1);
                if (opt & pos) {
                    comp += u[i];
                    comp -= z[i];
                } else {
                    comp += z[i];
                    comp -= u[i];
                }
                cpy ^= pos;
                if (seen.find(cpy) == seen.end()) {
                    seen.insert(cpy);
                    pq.push({-comp, cpy});
                }
            }
        }
    }
    return 0;
}
