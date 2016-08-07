#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 100010;

char s[N];
bool a[N], mark[N];

int main() {
	
	int T, n, i;
	scanf("%d", &T);

	vector <int> vi;
	
	char c;
	while (T--) {
		scanf("%d", &n);
		
		scanf("%s", s);

		a[0] = 0;
		for (i = 1; i <= n; ++i) {
			a[n - i + 1] = (s[i-1] == 'B') ? 0 : 1;
		}

		memset(mark, false, sizeof mark);
		vi.clear();

		int i = 1, left = 1;
		while (i <= n) {
			if (!mark[i] && a[i]) {
				mark[i] = true;
				a[i-1] ^= 1; a[i+1] ^= 1;
				vi.push_back(n - i + 1);
				if (a[i-1] && i > 1) {
					i -= 1;
				} else {
					i = left;
				}
				continue;
			} else {
				left = max(left, i);
			}
			i++;
		}

		if (vi.size() == n) {
			printf("Y\n");
			for (int x : vi) printf("%d ", x);
		} else printf("N");

		printf("\n");
	}

	return 0;
}