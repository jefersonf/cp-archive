#include <cstdio>
#include <fstream>
using namespace std;

int b[1000100];

int main() {
	
	freopen("antiqs.in", "rt", stdin);
	freopen("antiqs.out", "wt", stdout);

	int n, i;
	scanf("%d", &n);

	if (n == 1) {
		printf("1\n");
	} else if (n == 2) {
		printf("1 2\n");
	} else if (n == 3) {	
		printf("1 3 2\n");
	} else {
		b[1] = 1;
		b[2] = 4;
		b[3] = 2;
		b[4] = 3;
		for (i = 5; i <= n; ++i) {
			int m = (1 + i) / 2;
			b[i] = b[m];
			b[m] = i;
		}
		for (int i = 1; i <= n; ++i) {
			if (i > 1) printf(" ");
			printf("%d", b[i]);
		}
		printf("\n");
	}

	return 0;
}
