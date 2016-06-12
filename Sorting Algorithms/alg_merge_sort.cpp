#include <cstdio>

const int MaxN = 10010;

int n, a[MaxN], b[MaxN]; 

void merge_sort(int l, int r) {
	
	if (l == r) return;

	int mid = (l + r) / 2;

	merge_sort(l, mid);
	merge_sort(mid + 1, r);

	int m = 0;
	int j = mid + 1;

	for (int i = l; i <= mid; ++i) {
		while (j <= r && a[j] < a[i]) {
			b[m++] = a[j];
			j++;
		}
		b[m++] = a[i];
	}

	while (j <= r) {
		b[m++] = a[j];
		j++;
	}

	for (int i = l; i <= r; ++i) a[i] = b[i-l];
}

int main() {
	
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);

	merge_sort(0, n - 1);

	for (int i = 0; i < n; ++i)
		printf("%d ", a[i]);

	printf("\n");
	return 0;
}