#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <fstream>
using namespace std;

#define Pi (acos(-1.0))
#define eps 1e-12

struct point {
	double x, y;
	point() {}
	point(double _x, double _y) : x(_x), y(_y) {}
	point operator +(const point &q) const { return point(x+q.x, y+q.y); }
	point operator -(const point &q) const { return point(x-q.x, y-q.y); } 		
	point operator *(double c) const { return point(x*c, y*c); }
	point operator /(double c) const { return point(x/c, y/c); }
};

point rotate(point c, point &p, double theta) {
	double rad = theta*Pi/180.0;
	point q = p - c;
	double x = q.x*cos(rad) - q.y*sin(rad);
	double y = q.x*sin(rad) + q.y*cos(rad);
	return point(x, y) + c;
}

double dist(point &a, point &b) {
	return hypot(b.x - a.x, b.y - a.y);	
}

int main() {

	freopen("chairs.in", "rt", stdin);
	freopen("chairs.out", "wt", stdout);

	double a, b, c;
	cin >> a >> b >> c;
	
	double l[] = {a, b, c};
	
	sort(l, l + 3);
	a = l[0]; b = l[1]; c = l[2];
	
	point center(0, 0);
	point p(b, 0);
	point t(c, 0);
	point q;
	
	double lo = 0, hi = 90.0;
	while (fabs(hi - lo) > eps) {
		double theta = (lo + hi) / 2.0;
		q = rotate(center, p, theta);
		double d = dist(q, t); 
		if (fabs(d - a) < eps) break;
		if (d > a) {
			hi = theta;
		} else {
			lo = theta;
		}
	}
	
	point mid1 = (center + q) / 2;
	point mid2 = t / 2;
	point mid3 = (q + t) / 2;
	
	double ave = (dist(mid1, mid2) + dist(mid1, mid3) + dist(mid2, mid3)) / 3.0;
	cout << fixed << setprecision(16) << ave << endl;
	return 0;
}