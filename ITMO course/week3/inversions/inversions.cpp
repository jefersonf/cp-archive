#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;

const int N = 100100;

long long inv;
int a[N], w[N];

void merge_sort(int l, int r) {
	if (l == r) return;
	int m = (l + r) / 2;
	merge_sort(l, m);
	merge_sort(m + 1, r);
	int k = 0, p = m + 1;
	for (int i = l; i <= m; ++i) {
		while (p <= r && a[p] < a[i]) {
			w[k++] = a[p++];
			inv += m - i + 1;
		}
		w[k++] = a[i];
	}

	while (p <= r) w[k++] = a[p++];
	for (int i = l; i <= r; ++i) a[i] = w[i-l];
}

int main() {

	freopen("inversions.in", "rt", stdin);
	freopen("inversions.out", "wt", stdout);
	
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	inv = 0LL;
	merge_sort(0, n-1);
	printf("%lld\n", inv);
	return 0;
}