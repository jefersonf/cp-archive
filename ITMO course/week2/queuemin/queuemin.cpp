#include <iostream>
#include <map>
#include <vector>
#include <fstream>
using namespace std;

const int N = 1000100;
const int Inf = 1000000010;

struct Node {
	int v;
	Node() { v = Inf; }
} tree[4*N];

void upd(int id, int l, int r, int pos, int val) {
	if (l == r) {
		tree[id].v = val;
		return;
	}
	int mid = (l + r)/2;
	if (pos <= mid) upd(id*2, l, mid, pos, val);
	else upd(id*2+1, mid+1, r, pos, val);
	tree[id].v = min(tree[id*2].v, tree[id*2+1].v);
}

Node queryMin(int id, int i, int j, int l, int r) {
	if (r < i || l > j) return Node();
	if (i >= l && j <= r) return tree[id];
	int mid = (i + j)/2;
	Node _left = queryMin(id*2, i, mid, l, r);
	Node _right = queryMin(id*2+1, mid + 1, j, l, r);
	if (_left.v < _right.v) return _left;
	return _right;
}

int main() {

	freopen("queuemin.in", "rt", stdin);
	freopen("queuemin.out", "wt", stdout);

	int n, x; char o;
	scanf("%d", &n);

	int k = 1, cnt_del = 0;
	for (int i = 1; i <= n; ++i) {
		scanf(" %c", &o);
		if (o == '+') {
			scanf("%d", &x);
			upd(1, 1, n, k++, x);
		} else if (o == '-') {
			cnt_del++;
		} else {
			printf("%d\n", queryMin(1, 1, n, cnt_del + 1, k).v);
		}
	}

	return 0;
}