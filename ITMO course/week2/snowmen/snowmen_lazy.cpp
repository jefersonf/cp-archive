#include <iostream>
#include <stack>
#include <queue>
#include <fstream>
using namespace std;

const int N = 1000100;

typedef long long ll;

ll sum[N];
stack <ll> a[N];

int main() {
	
	//freopen("snowmen_gen.in", "rt", stdin);
	//freopen("snowmen_gen.out", "wt", stdout);

	// Naive solution

	int n;
	sum[0] = 0ll;
	int t; ll m;

	a[0].push(0ll);
	stack <ll> tmp0;

	while (cin >> n) {
		ll ans = 0ll;

		for (int i = 1; i <= n; ++i) {
			cin >> t >> m;

			sum[i] = 0ll;
			while (!a[t].empty()) {
				tmp0.push(a[t].top());
				a[t].pop();
			}

			while (!tmp0.empty()) {
				a[i].push(tmp0.top());
				a[t].push(tmp0.top());
				tmp0.pop();
			}

			if (m == 0) {
				if (!a[t].empty()) {
					sum[i] = sum[t] - a[t].top();
					a[i].pop();
				}
			} else {
				sum[i] = sum[t] + m;
				a[i].push(m);
			}
			ans += sum[i];
		}

		for (int i = 1; i <= n; ++i) {
			while (!a[i].empty()) a[i].pop();
			sum[i] = 0ll;
		}

		cout << ans << endl;
	}

	return 0;
}
