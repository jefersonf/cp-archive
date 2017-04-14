#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

int t[16];

int main() {

	freopen("win.in", "rt", stdin);
	freopen("win.out", "wt", stdout);

	int i, n;
	cin >> n;

	for (i = 0; i < n; ++i) cin >> t[i];

	sort(t, t + n);
	int r = 18000, ans = 0;
	for (i = 0; i < n; ++i) {
		if (t[i] <= r) {
			ans++;
			r -= t[i];
		} else break;
	}

	cout << ans << endl;
	return 0;
}
