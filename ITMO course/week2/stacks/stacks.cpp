#include <cstdio>
#include <queue>
#include <fstream>
using namespace std;

struct Cup {
	int height;
	Cup() {}
	Cup(int h) : height(h) {}
	bool operator <(const Cup &other) const {
		return height > other.height;
	}
};

priority_queue <Cup> cups;

int main() {
	
	freopen("stacks.in", "rt", stdin);
	freopen("stacks.out", "wt", stdout);

	int n, c;
	scanf("%d", &n);

	int ans = 1;
	while (n--) {
		scanf("%d", &c);
		if (c == 0) {
			if (!cups.empty()) {
				Cup q = cups.top();
				cups.pop();
				q.height++;
				cups.push(q);
				if (q.height > ans) ans = q.height;
			} else {
				cups.push(Cup(1));
			}
		} else {
			cups.push(Cup(1));
		}
	}

	printf("%d\n", ans);
	return 0;
}