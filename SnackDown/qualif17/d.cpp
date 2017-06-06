#include <bits/stdc++.h>
using namespace std;

struct snake {
  int xi, yi, xj, yj;
  snake() {}
};

bool pointInLineCase(snake a, snake b) {
  int mn_x, mx_x, mn_y, mx_y;
  bool ret = false;
  if (a.xi == a.xj && a.yi == a.yj) {
    mn_x = min(b.xi, b.xj);
    mx_x = max(b.xi, b.xj);
    mn_y = min(b.yi, b.yj);
    mx_y = max(b.yi, b.yj);
    ret = (a.xi >= mn_x && a.xi <= mx_x) && (a.yi >= mn_y && a.yi <= mx_y);
  } else if (b.xi == b.xj && b.yi == b.yj) {
    mn_x = min(a.xi, a.xj);
    mx_x = max(a.xi, a.xj);
    mn_y = min(a.yi, a.yj);
    mx_y = max(a.yi, a.yj);
    ret = (b.xi >= mn_x && b.xi <= mx_x) && (b.yi >= mn_y && b.yi <= mx_y);
  }
  return ret;
}

bool vertical(snake a, snake b) {
  int mn = min(b.yi, b.yj);
  int mx = max(b.yi, b.yj);
  bool ret = (a.yi >= mn) && (a.yi <= mx);
  ret = ret || ((a.yj >= mn) && (a.yj <= mx));
  return ret;
}

bool horizontal(snake a, snake b) {
  int mn = min(b.xi, b.xj);
  int mx = max(b.xi, b.xj);
  bool ret = (a.xi >= mn) && (a.xi <= mx);
  ret = ret || ((a.xj >= mn) && (a.xj <= mx));
  return ret;
}

bool corner(snake a, snake b) {
  bool ret = ((a.xi == b.xi && a.yi == b.yi));
  ret = ret || ((a.xi == b.xj && a.yi == b.yj));
  ret = ret || ((a.xj == b.xi && a.yj == b.yi));
  ret = ret || ((a.xj == b.xj && a.yj == b.yj));
  return ret;
}

int main() {

  // freopen("test.in", "r", stdin);

  int T;
  scanf("%d", &T);

  while (T--)
  {
    snake A, B;
    scanf("%d %d %d %d", &A.xi, &A.yi, &A.xj, &A.yj);
    scanf("%d %d %d %d", &B.xi, &B.yi, &B.xj, &B.yj);

    bool resp = pointInLineCase(A, B);
    if (A.xi == A.xj) {
      if (B.xi == B.xj) {
        if (A.xi == B.xi) {
          resp = resp || vertical(A, B);
          resp = resp || vertical(B, A);
        }
      } else {
        resp = resp || corner(A, B);
      }
    } else {
      if (B.xi == B.xj) {
        resp = resp || corner(A, B);
      } else {
        if (A.yi == B.yi) {
          resp = resp || horizontal(A, B);
          resp = resp || horizontal(B, A);
        }
      }
    }

    if (resp) {
      printf("yes\n");
    } else {
      printf("no\n");
    }
  }

  return 0;
}
