#include <cstdio>
#include <deque>
#include <fstream>
using namespace std;

int p = 1;
deque <int> d[2];

int main() {

	freopen("kenobi.in", "rt", stdin);
	freopen("kenobi.out", "wt", stdout);
	
	int n, x, sz;
	scanf("%d", &n);

	char cmd[5];
	sz = 0;
	while (n--) {
		scanf("%s[^dku]", cmd);
		if (sz > 0) {				
			if (d[p].size() < d[1-p].size()) {
				d[p].push_front(d[1-p].back());
				d[1-p].pop_back();
			} else if (d[p].size() > d[1-p].size() + 1) {
				d[1-p].push_back(d[p].front());
				d[p].pop_front();
			}
		}

		if (sz == 1) {
			if (p == 0) {
				p = 1;
				d[p].push_front(d[1-p].back());
				d[1-p].pop_back();
			}
		} else if (sz == 0) p = 1;

		if (cmd[0] == 'a') {
			scanf("%d", &x);
			d[p].push_back(x);
			sz++;
		} else if (cmd[0] == 't') {
			d[p].pop_back();
			sz--;
		} else {
			p ^= 1;
		}
	}

	if (sz > 0) {				
		if (d[p].size() < d[1-p].size()) {
			d[p].push_front(d[1-p].back());
			d[1-p].pop_back();
		} else if (d[p].size() > d[1-p].size() + 1) {
			d[1-p].push_back(d[p].front());
			d[p].pop_front();
		}
	}

	if (sz == 1) {
		if (p == 0) {
			p = 1;
			d[p].push_front(d[1-p].back());
			d[1-p].pop_back();
		}
	} else if (sz == 0) p = 1;

	printf("%d\n", sz);

	bool f = false;
	while (!d[1-p].empty()) {
		if (f) printf(" ");
		f = true;
		printf("%d", d[1-p].front());
		d[1-p].pop_front();
	}

	while (!d[p].empty()) {
		if (f) printf(" ");	
		f = true;
		printf("%d", d[p].front());
		d[p].pop_front();
	}

	printf("\n");
	return 0;
}

