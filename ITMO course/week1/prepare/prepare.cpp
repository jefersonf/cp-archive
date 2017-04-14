#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

int t[110], p[110];

int main() {

	freopen("prepare.in", "rt", stdin);
	freopen("prepare.out", "wt", stdout);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) cin >> p[i];
	for (int i = 0; i < n; ++i) cin >> t[i];

	bool t_some = false, p_some = false;
	int sum = 0;

	for (int i = 0; i < n; ++i) {
		if (t[i] > p[i]) {
			t_some = true;
			sum += t[i];
		} else {
			p_some = true;
			sum += p[i];
		}
	}

	int ans = 0;
	if (!t_some) {
		for (int i = 0; i < n; ++i)
			ans = max(ans, sum - p[i] + t[i]);
	} else if (!p_some) {
		for (int i = 0; i < n; ++i)
			ans = max(ans, sum - t[i] + p[i]);
	} else {
		ans = sum;
	}
	
	cout << ans << endl;
	return 0;
}