#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <fstream>
using namespace std;

const int N = 100100;

int a[N], b[N], t[N];

void quickSort(int l, int r) {
	int i = l, j = r, p = a[l + rand()%(r-l+1)];
	while (i <= j) {
		while (a[i] < p) i++;
		while (p < a[j]) j--;
		if (i <= j) {
			if (i < j) t[i] = j;
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			i++;
			j--;
		}
	}
	if (l < j) quickSort(l, j);
	if (i < r) quickSort(i, r);
}

int main() {
	// Wrong answer, test #3
	freopen("scarecrow.in", "rt", stdin);
	freopen("scarecrow.out", "wt", stdout);

	int n, k, i;
	scanf("%d %d", &n, &k);

	for (i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		b[i] = a[i];
		t[i] = -1;
	}

	quickSort(0, n - 1);
	for (i = 0; i < n; ++i) if (t[i] != -1 && (t[i] - i) == k) {
		int tmp = b[i]; b[i] = b[t[i]]; b[t[i]] = tmp;
	}

	bool ans = true;
	for (i = 1; i < n; ++i) {
		if (b[i] < b[i-1]) ans = false;
	}

	puts(ans ? "YES" : "NO");
	return 0;
}
