#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

#define pb push_back

typedef long long ll;
typedef vector<int> vi;

vi ans;

void solve(ll n) {
	ans.clear();
	for (ll b = 2; b <= 16; ++b) {
		ll au = n;
		vi d;
		while (au > 0) {
			d.pb( au % b );
			au /= b;
		}

		bool is_palim = true;
		int m = (int) d.size();
		for (int i = 0; is_palim && i < m / 2; ++i) {
			if (d[i] != d[m-i-1]) is_palim = false;
		}

		if (is_palim) ans.pb(b);
	}
}

int main() {
	
	int T;
	scanf("%d", &T);

	ll n;
	while (T--) {
		scanf("%lld", &n);
		solve(n);
		if (ans.size() == 0) printf("-1");
		else {
			for (int b : ans)  printf("%d ", b);
		}
		puts("");
	}

	return 0;
}