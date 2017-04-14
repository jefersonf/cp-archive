#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <fstream>
using namespace std;

const int N = 100100;

int a[N], h[N], d[N];

void quickSort(int l, int r) {
	int i = l, j = r, p = a[l + (rand() % (r - l + 1))];
	while (i <= j) {
		while (a[i] < p) i++;
		while (p < a[j]) j--;
		if (i <= j) {
			int t = a[i]; a[i] = a[j]; a[j] = t;
			i++;
			j--;
		}
	}
	if (l < j) quickSort(l, j);
	if (i < r) quickSort(i, r);
}

int main() {

	freopen("drying.in", "rt", stdin);
	freopen("drying.out", "wt", stdout);

	int i, j, n, k;
	scanf("%d", &n);

	d[n] = -1;
	for (i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		d[n - i - 1] = 1 + d[n-i];
	}

	scanf("%d", &k);
	quickSort(0, n - 1);

	i = 0;
	int t = 0, mx = 0;
	for (int j = n - 1; j >= 0; --j) {
		if ((a[j] - t - d[j]) > k) {
			t += (a[j] - t - d[j]) / (k - 1);
		}
		a[j] = (a[j] - t - d[j]);
		if (a[j] < 0) a[j] = 0;
		mx = max(mx, a[j]);
	}

	t += mx;
	printf("%d\n", t);
	return 0;
}
