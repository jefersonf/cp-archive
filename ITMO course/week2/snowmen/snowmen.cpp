#include <cstdio>
#include <fstream>
using namespace std;

typedef unsigned long long ll;
	
const int N = 1000100;

ll sum[N], pre[N], top[N], sz[N];

int main() {
	
	freopen("snowmen.in", "rt", stdin);
	freopen("snowmen.out", "wt", stdout);

	int i, n, t, m;

	scanf("%d", &n);
	ll ans = 0LL;
	sum[0] = 0LL;
	sz[0] = top[0] = pre[0] = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d %d", &t, &m);
		pre[i] = t;
		if (m == 0) {
			sum[i] = sum[t] - top[t];
			sz[i] = sz[t] - 1;
			while (sz[pre[i]] != sz[i]) {
				pre[i] = pre[pre[i]];
				if (pre[i] == 0) break;
			}
			top[i] = top[pre[i]];
		} else {
			sum[i] = sum[t] + (ll)m;
			top[i] = m;
			sz[i] = sz[t] + 1;
		}
		ans += sum[i];
	}

	printf("%lld\n", ans);
	return 0;
}