#include <cstdio>
#include <algorithm>
using namespace std;

int pwr(int a, int n) {
	if (n == 0) return 1LL;
	if (n == 1) return a;
	if (n & 1)
		return a * pwr(a, n-1);
	int h = pwr(a, n/2);
	return h*h;
}

int main() {
	
	int T;
	scanf("%d", &T);

	int c, d, ans;
	while (T--) {
		scanf("%d %d", &c, &d);
		ans = pwr(26, c) * pwr(10, d);
		printf("%d\n", (ans == 1) ? 0 : ans);
	}

	return 0;
}