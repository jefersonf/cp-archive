#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

void taskSnowmen(int N) {
	while (N--) {
		int n = rand() % 99 + 1;
		int any_non_empty = false;
		printf("%d\n", n);
		int cnt = 0;
		for (int j = 1; j <= n; ++j) {
			int t = rand() % j;
			int m = rand() % 5;
			if (m > 0) {
				cnt++;
			} else cnt--;

			if (m == 0 && cnt <= 0) {
				m = rand() % 10 + 1;
				cnt++;
			}
			printf("%d %d\n", t, m);
		}
	}
}

void taskKenobi(int N) {
	int sz = 0;
	printf("%d\n", N);
	int k = rand() % 100 + 100;
	while (N--) {
		int n = rand() % 3;
		if (k > 0) n = 0, k--;
		if (n == 0) { // add
			int p = rand() % 100 + 1;
			printf("add %d\n", p);
			sz++;
		} else if (n == 1) { // take
			if (sz > 0) {
				printf("take\n");
			} else {
				printf("mum!\n");
			}
			sz--;
		} else {
			printf("mum!\n");
		}
	}
}

void taskAntiqs(int m) {
	int a[1000];
	for (int i = 1; i <= m; ++i) a[i] = i;
	do {
		printf("%d\n", m);
		for (int i = 1; i <= m; ++i) {
			printf("%d ", a[i]);
		}
		printf("\n");
	} while (next_permutation(a+1, a+m+1));
}

int main() {
	
	// freopen("snowmen_gen.in", "wt", stdout);
	// taskSnowmen(100);

	// freopen("kenobi_gen.in", "wt", stdout);
	// taskKenobi(10000);

	freopen("antiqs.in", "wt", stdout);
	taskAntiqs(5);

	return 0;
}