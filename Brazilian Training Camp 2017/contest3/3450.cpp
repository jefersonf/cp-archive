#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct boss {
  int d, d2, t;
  boss(){}
  bool operator <(const boss &o) const {
    if (d == o.d) return t > o.t;
    return d > o.d;
  }
};

priority_queue<boss> qu;

int main()  { // BOSS RUSH

  int i, T, n;
  scanf("%d", &T);

  while (T--)
  {
      scanf("%d", &n);
      boss B;
      for (i = 0; i < n; ++i) {
        scanf("%d %d", &B.d, &B.d2);
        B.t = 1;
        qu.push(B);
      }

      int stars = 0, traded = 0;
      while (!qu.empty()) {
        boss cur = qu.top();
        qu.pop();
        if (cur.t == 0) {
          if (stars >= cur.d) {
            stars += 2;
          } else {
            traded += (cur.d - stars);
            stars  += (cur.d - stars);
            stars  += 2;
          }
        } else {
          if (stars < cur.d) {
            traded += (cur.d - stars);
            stars  += (cur.d - stars);
          }
          stars  += 1;
          cur.d = cur.d2;
          cur.t = 0;
          qu.push(cur);
        }
      }

      printf("%d\n", traded);
  }

  return 0;
}
