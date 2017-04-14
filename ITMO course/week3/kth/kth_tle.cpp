#include <cstdio>
#include <algorithm>
#include <cstdio>
#include <fstream>
using namespace std;

const int N = 40000100;

int a[N];

/*
void quisckSort(int l, int r, int k) {
	int i = l, j = r, p = a[l + (rand() % (r - l + 1))];
	while (i <= j) {
		while (a[i] < p) i++;
		while (p < a[j]) j--;
		if (i <= j) {
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			i++;
			j--;
		}
	}

	if (l <= j && k <= j) quickSort(l, j, k);
	if (i <= r && i <= k) quickSort(i, r, k);
}*/


int partition(int l, int r) {
	int p = l + (rand() %(r - l + 1));
	int t = a[p]; a[p] = a[r]; a[r] = t;
	int j = l;
	for (int i = l; i < r; ++i) {
		if (a[i] <= a[r]) {
			t = a[i];
			a[i] = a[j];
			a[j] = t;
			j++;
		}
	}
	t = a[j];
	a[j] = a[r];
	a[r] = t;
	return j;
}

void quickSort(int l, int r, int k) {
	if (l < r) {
		int pi = partition(l, r);
		if (l <= pi + 1 && k <= pi - 1)
			quickSort(l, pi - 1, k);
		if (pi + 1 <= r && pi + 1 <= k)
			quickSort(pi + 1, r, k);
	}
}

void _sort(int n, int k) {
	quickSort(0, n - 1, k);
}

int main() {

	freopen("kth.in", "rt", stdin);
	//freopen("kth.out", "wt", stdout);

	int n, i, k1, k2;
	scanf("%d %d %d", &n, &k1, &k2);

	int A, B, C;
	scanf("%d %d %d %d %d", &A, &B, &C, &a[0], &a[1]);

	for (i = 2; i < n; ++i) {
		a[i] = (int)(A*a[i-2] + B*a[i-1] + C);
	}

	_sort(n, k1 - 1);
	/*
	quickSort(0, n -1, k2 - 1);
	int l = a[k2 - 1], x, j = 0;
	for (i = k1 - 1; i < k2 - 1; ++i) {
		quisckSort(j, n - 1, i);
		x = a[i];
		if (x == l) {
			while (x == l && i < k2 - 1) {
				printf("%d ", x);
				i++;
			}
		} else {
			printf("%d ", a[i]);
		}
		j = i;
	}

	printf("%d\n", l);*/
	return 0;
}
