#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MN = 100010;

ll snake[MN], SUM[MN];

int solve(int N, ll K) {
  int ret = 0;
  int i = 0, j = N;
  while (i <= j) {
    int m = (i + j) / 2;
    int q = N - m + 1;
    ll p = K * ((ll) q) - SUM[m] + SUM[N + 1];
    if (((ll) m) >= p) {
      ret = max(ret, q);
      j = m - 1;
    } else {
      i = m + 1;
    }
  }
  return ret;
}

int main() {

  // freopen("test.in", "r", stdin);

  int i, T, N, Q;
  scanf("%d", &T);

  while (T--)
  {
      scanf("%d %d", &N, &Q);
      for (i = 0; i < N; ++i) {
        scanf("%lld", &snake[i]);
        SUM[i] = 0LL;
      }

      sort(snake, snake + N);
      SUM[N] = 0LL;
      SUM[N - 1] = snake[N - 1];
      for (int i = N - 2; i >= 0; --i)
        SUM[i] = snake[i] + SUM[i+1];

      int resp;
      while (Q--) {
        ll K;
        scanf("%lld", &K);
        int p = lower_bound(snake, snake + N, K) - snake;
        if (p == 0) {
          resp = N;
        } else {
          resp = (N - p) + solve(p - 1, K);
        }
        printf("%d\n", resp);
      }
  }

  return 0;
}
