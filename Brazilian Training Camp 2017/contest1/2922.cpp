#include <bits/stdc++.h>
using namespace std;

#define eps 1e-9

struct point {
  double x, y;
  point() {}
  point(double x, double y) : x(x), y(y) {}
  point operator +(const point &p) { return point(x + p.x, y + p.y); }
  point operator -(const point &p) { return point(x - p.x, y - p.y); }
  point operator *(double c) { return point(x * c, y * c); }
  point operator /(double c) { return point(x / c, y / c); }
};

struct vec {
  double dx, dy;
  vec() {}
  vec(double x, double y) : dx(x), dy(y) {}
};

vec toVec(point a, point b) {
  return vec(b.x - a.x, b.y - a.y);
}

vec scale(vec v, double s) {
  return vec(v.dx * s, v.dy * s);
}

double dot(vec a, vec b) {
  return a.dx*b.dx + a.dy*b.dy;
}

double norm_sq(vec v) {
  return v.dx*v.dx + v.dy*v.dy;
}

point translate(point p, vec v) {
  return point(p.x + v.dx, p.y + v.dy);
}

double areaTriangulo(point &a, point &b, point &c) {
  double l1 = hypot(a.x - b.x, a.y - b.y);
  double l2 = hypot(a.x - c.x, a.y - c.y);
  double l3 = hypot(b.x - c.x, b.y - c.y);
  double s = (l1 + l2 + l3) / 2.0;
  return sqrt(s*fabs(l1 - s)*fabs(l2 - s)*fabs(l3 - s));
}

double angle(point a, point orig, point b) {
  vec oa = toVec(orig, a);
  vec ob = toVec(orig, b);
  return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

int main() {

  //freopen("2922.in", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int valid;
  point A, B, C, D, E, F;
  while (true) {
    cin >> A.x >> A.y;
    cin >> B.x >> B.y;
    cin >> C.x >> C.y;
    cin >> D.x >> D.y;
    cin >> E.x >> E.y;
    cin >> F.x >> F.y;

    valid = 1;
    valid &= (fabs(A.x) < eps && fabs(A.y) < eps);
    valid &= (fabs(B.x) < eps && fabs(B.y) < eps);
    valid &= (fabs(C.x) < eps && fabs(C.y) < eps);
    valid &= (fabs(D.x) < eps && fabs(D.y) < eps);
    valid &= (fabs(E.x) < eps && fabs(E.y) < eps);
    valid &= (fabs(F.x) < eps && fabs(F.y) < eps);

    if (valid) break;

    // area do triangulo DEF
    double area_triang = areaTriangulo(D, E, F);
    double dist_AB = hypot(A.x - B.x, A.y - B.y);
    double dist_AC = hypot(A.x - C.x, A.y - C.y);

    // altura do paralelograma
    double height = area_triang / dist_AB;

    // angulo BAC em radianos
    double theta = angle(B, A, C);
    double dist_AH = height / sin(theta);

    // escala o vetor A->C para o vetor A->H e translada A p/ H
    point H = translate(A, scale(toVec(A, C), dist_AH / dist_AC));
    point G = translate(H, toVec(A, B));
    cout << fixed << setprecision(3);
    cout << G.x <<" "<< G.y <<" "<< H.x <<" "<< H.y << "\n";
  }

  return 0;
}
