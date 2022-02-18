//Sample Problem
//Solution: Simple modular arithmetic application
#include <iostream>
using namespace std;

int main() {
    int t, i, j;
    cin >> t;
    for (i=1; i <= t; i++) {
        int n, m, s = 0;
        cin >> n >> m;
        for (j=0; j<n; j++) {
            int c;
            cin >> c;
            s += c;
        } 
        cout << "Case #" << i << ": " << (s % m) << endl;
    }
    return 0;
}
