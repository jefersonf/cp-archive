#include <cstdio>
#include <algorithm>
#include <cstdio>
#include <fstream>
using namespace std;

const int N = 40000010;

int a[N];

void quickSort(int l, int r, int k) {
	int i = l, j = r, p = a[l + rand()%(r-l+1)];
	while (i <= j) {
		while (a[i] < p) i++;
		while (p < a[j]) j--;
		if (i <= j) {
			int t = a[i];
			a[i] = a[j];
			a[j] = t;
			i++;
			j--;
		}
	}
	if (l <= j && k <= j) quickSort(l, j, k);
	else if (i <= r && i <= k) quickSort(i, r, k);
}

int main() {
	// Wrong answer, test #32     I'm really sad
	freopen("kth.in", "rt", stdin);
	freopen("kth.out", "wt", stdout);

	int n, i, k1, k2;
	scanf("%d %d %d", &n, &k1, &k2);

	int A, B, C;
	scanf("%d %d %d %d %d", &A, &B, &C, &a[0], &a[1]);

	for (i = 2; i < n; ++i) {
		a[i] = (int)(A*a[i-2] + B*a[i-1] + C);
	}

	for (i = k1 - 1; i < k2; ++i) {
		if (i >= k1) printf(" ");
		quickSort(0, n - 1, i);
		printf("%d", a[i]);
	}

	printf("\n");
	return 0;
}
