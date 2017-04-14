#include <iostream>
#include <fstream>
using namespace std;

const int N = 1000100;

int Queue[N], head = 0, tail = 0;

int main() {

	ios::sync_with_stdio(0);

	freopen("queue.in", "rt", stdin);
	freopen("queue.out", "wt", stdout);

	int n, x; char o;
	scanf("%d", &n);

	while (n--) {
		scanf(" %c", &o);
		if (o == '+') {
			scanf("%d", &x);
			Queue[tail++] = x;
		} else {
			printf("%d\n", Queue[head]);
			head++;
			if (head == tail) {
				head = tail = 0;
			}
		}
	}

	return 0;
}