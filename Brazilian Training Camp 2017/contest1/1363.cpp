#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100100;
double EPS = 1e-9;

int N;
double x[MAXN], y[MAXN];
int p[MAXN];

pair<double, double> Dist(double z1, double z2, char axis) {
  double s1 = 0.0, s2 = 0.0, f1 = 0.0, f2 = 0.0;
  for (int i = 0; i < N; ++i) {
    if (axis == 'x') {
      f1 = fabs(x[i] - z1);
      f2 = fabs(x[i] - z2);
    } else {
      f1 = fabs(y[i] - z1);
      f2 = fabs(y[i] - z2);
    }
    if (p[i] == 0) {
      s1 += 1.0;
      s2 += 1.0;
    } else if (p[i] == 1) {
      s1 += f1;
      s2 += f2;
    } else if (p[i] == 2) {
      s1 += f1*f1;
      s2 += f2*f2;
    } else {
      s1 += f1*f1*f1;
      s2 += f2*f2*f2;
    }
  }

  return {s1, s2};
}

int main() {

  double INF = (double) INT_MAX;

  int T;
  scanf("%d", &T);

  while (T--) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
      scanf("%lf %lf %d", &x[i], &y[i], &p[i]);
    }

    pair<double, double> d;
    double lo = -INF, hi = INF;
    double t, m1, m2, resp = 0.0;
    while (hi - lo > EPS) {
      m1 = lo + (hi - lo)/3.0;
      m2 = hi - (hi - lo)/3.0;
      d = Dist(m1, m2, 'x');
      if (d.first < d.second) {
        hi = m2;
      } else {
        lo = m1;
      }
    }

    resp += Dist(hi, hi, 'x').first;

    lo = -INF;
    hi = INF;
    while (hi - lo > EPS) {
      m1 = lo + (hi - lo)/3.0;
      m2 = hi - (hi - lo)/3.0;
      d = Dist(m1, m2, 'y');
      if (d.first < d.second) {
        hi = m2;
      } else {
        lo = m1;
      }
    }

    resp += Dist(hi, hi, 'y').first;
    printf("%.3lf\n", resp);

  }

  return 0;
}
