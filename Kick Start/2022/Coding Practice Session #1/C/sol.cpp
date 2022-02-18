//H-Index
//Solution: Fenwick Tree + Binary Search
#include <iostream>
#include <vector>
#include <map>
#define br(n) " \n"[n]
using namespace std;
const int N = 100100;
int tree[N];

void add(int i) {
    while (i < N) tree[i] += 1, i += i&(-i);
}

int query(int i) {
    int c = 0;
    while (i > 0) c += tree[i], i -= i&(-i);
    return c;
}

int main() {
    int t; cin >> t;
    for (int i=1; i<=t; i++) {
        int n; cin >> n;
        for (int k=0; k<N; k++) tree[k]=0;
        cout << "Case #" << i << ": ";
        int h = 1, m = 0;
        for (int j=0; j<n; j++) {
            int a;
            cin >> a;
            add(a);
            m = max(m, a);
            if (j > 0) {
                int count = query(m + 1);
                int lo = 1, hi = j + 1;
                while (lo <= hi) {
                    int k = (lo + hi) / 2;
                    int q = count - query(k-1);
                    if (q >= k) {
                        h = max(h, k);
                        lo = k + 1;
                    } else hi = k - 1;
                }
            }
            cout << h << br(j==n-1);
        }
    }
    return 0;
}
