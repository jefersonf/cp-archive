#include <iostream>
#include <fstream>
using namespace std;

const int N = 1000100;

int Stack[N], top = 0;

int main() {

	ios::sync_with_stdio(0);

	freopen("stack.in", "rt", stdin);
	freopen("stack.out", "wt", stdout);

	int n, x; char o;
	scanf("%d", &n);

	while (n--) {
		scanf(" %c", &o);
		if (o == '+') {
			scanf("%d", &x);
			Stack[top++] = x;
		} else {
			if (top > 0) {
				printf("%d\n", Stack[--top]);
			}
		}
	}

	return 0;
}