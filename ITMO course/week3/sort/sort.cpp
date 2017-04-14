#include <cstdio>
#include <fstream>
using namespace std;

const int N = 200010;

int n, a[N], w[N];

void merge_sort(int l, int r) {
	if (l+1 == r) {
		printf("%d %d %d %d\n", r, r, a[r-1], a[r-1]);
		return;
	}
	int m  = (l + r) / 2;
	merge_sort(l, m);
	merge_sort(m, r);
	int i = l, j = m, k = l;
	while (i < m || j < r) {
		if (j == r || (i < m && a[i] < a[j])) {
			w[k++] = a[i++];
		} else {
			w[k++] = a[j++];
		}
	}

	for (i = l; i < r; ++i) a[i] = w[i];
	printf("%d %d %d %d\n", l+1, r, a[l], a[r-1]);
}

int main() {
	
	freopen("sort.in", "rt", stdin);
	freopen("sort.out", "wt", stdout);

	int i;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) scanf("%d", &a[i]);
	merge_sort(0, n);
	for (i = 0; i < n; ++i) {
		if (i) printf(" ");
		printf("%d", a[i]);
	}
	printf("\n");
	return 0;
}

