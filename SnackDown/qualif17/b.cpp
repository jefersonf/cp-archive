#include <bits/stdc++.h>
using namespace std;

int h[110];

int main() {

  freopen("test.in", "r", stdin);

  int i, S, N;
  cin >> S;

  while (S--) {
    cin >> N;
    int resp = 1;
    for (i = 0; i < N; ++i) {
      cin >> h[i];
    }
    if (N % 2) {
      resp &= (h[0] == 1);
      resp &= (h[N-1] == 1);
      int M = N/2;
      for (i = 1; i <= M; ++i) {
        resp &= (h[i] - h[i-1] == 1);
        resp &= (h[M + i - 1] - h[M + i] == 1);
      }
    } else {
      resp = 0;
    }

    if (resp) {
      printf("yes\n");
    } else {
      printf("no\n");
    }
  }

  return 0;
}
