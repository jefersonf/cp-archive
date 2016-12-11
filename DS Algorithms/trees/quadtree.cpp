#include <bits/stdc++.h>
using namespace std;

#define N   512
#define Inf (1LL << 30)
#define UL(i) (4*i - 2)
#define UR(i) (4*i - 1)
#define DL(i) (4*i + 0)
#define DR(i) (4*i + 1)

typedef long long ll;

ll grid[N][N];

struct Segment {
	int x, y; 
	ll value;
	Segment() {}
	Segment(int x, int y, ll v) : x(x), y(y), value(v) {}

	bool operator <(const Segment& other) const {
		return value < other.value;
	}
};

struct Segtree2d {
	
	int n, m;
	bool isRMQ = false;

	Segment tree[500000];

	void init(int width, int height, bool rmq=false) {
		this->n = width;
		this->m = height;
		this->isRMQ = rmq;
		build(1, 1, 1, width, height);
	}

	Segment build(int id, int x0, int y0, int x1, int y1) {
		if (x0 > x1 || y0 > y1) return nil();
		if (x0 == x1 && y0 == y1)
			return tree[id] = Segment(x0, y0, grid[x0][y0]);
		
		int midx = (x0 + x1) / 2, midy = (y0 + y1) / 2;

		tree[id] = nil();
		tree[id] = fun(tree[id], build(UL(id), x0, y0, midx, midy));
		tree[id] = fun(tree[id], build(UR(id), midx + 1, y0, x1, midy));
		tree[id] = fun(tree[id], build(DL(id), x0, midy + 1, midx, y1));
		tree[id] = fun(tree[id], build(DR(id), midx + 1, midy + 1, x1, y1));

		return tree[id];
	}

	Segment query(int id, int x0, int y0, int x1, int y1, int a, int b, int c, int d) {
		if (x0 > c || x1 < a || y0 > d || y1 < b || x0 > x1 || y0 > y1)
			return nil();

		if (a <= x0 && b <= y0 && x1 <= c && y1 <= d)
			return tree[id];

		int midx = (x0 + x1) / 2, midy = (y0 + y1) / 2;
	
		Segment answer = nil();
		answer = fun(answer, query(UL(id), x0, y0, midx, midy, a, b, c, d));
		answer = fun(answer, query(UR(id), midx + 1, y0, x1, midy, a, b, c, d));
		answer = fun(answer, query(DL(id), x0, midy + 1, midx, y1, a, b, c, d));
		answer = fun(answer, query(DR(id), midx + 1, midy + 1, x1, y1, a, b, c, d));

		return answer;
	}

	Segment query(int x0, int y0, int x1, int y1) {
		return query(1, 1, 1, n, m, x0, y0, x1, y1);
	}

	Segment update(int id, int x0, int y0, int x1, int y1, int x, int y, ll value) {
		if (x0 > x1 || y0 > y1) return nil();

		if (x > x1 || x < x0 || y > y1 || y < y0) return tree[id];
		
		if (x0 == x && x1 == x && y0 == y && y1 == y)
			return tree[id] = Segment(x, y, value);

		int midx = (x0 + x1) / 2, midy = (y0 + y1) / 2;
		
		Segment answer = nil();
		answer = fun(answer, update(UL(id), x0, y0, midx, midy, x, y, value));
		answer = fun(answer, update(UR(id), midx + 1, y0, x1, midy, x, y, value));
		answer = fun(answer, update(DL(id), x0, midy + 1, midx, y1, x, y, value));
		answer = fun(answer, update(DR(id), midx + 1, midy + 1, x1, y1, x, y, value));

		return tree[id] = answer;
	}

	Segment update(int x, int y, int value) {
		return update(1, 1, 1, n, m, x, y, value);
	}

	Segment fun(Segment a, Segment b) {
		return (this->isRMQ) ? min(a, b) : max(a, b);
	}

	Segment nil() {
		if (this->isRMQ)
			return Segment(0, 0, Inf);
		return Segment(0, 0, -Inf);
	}
};

int main() {

	// read grid[N][N]
	// init QuadTree
	// be happy
}