#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 105;
const int Inf = 1000;

int f[2][N], cp[2][N];

int round() {
  for (int k = 0; k < N; ++k) {
    cp[0][k] = f[0][k];
    cp[1][k] = f[1][k];
  }
  int ans = -Inf;
  int i = 1, j = 100;
  while (i <= 100 && j > 0) {
    if (cp[0][i] == 0) {
      i++;
    } else if (cp[1][j] == 0) {
      j--;
    } else {
        ans = max(ans, i + j);
        if (cp[0][i] < cp[1][j]) {
          cp[1][j] -= cp[0][i];
          i++;
        } else if (cp[0][i] > cp[1][j]) {
          cp[0][i] -= cp[1][j];
          j--;
        } else {
          i++;
          j--;
        }
    }
  }
  return ans;
}

int main() {

  int i, n;
  scanf("%d", &n);

  int x, y;
  for (i = 0; i < n; ++i) {
    scanf("%d %d", &x, &y);
    f[0][x]++;
    f[1][y]++;
    printf("%d\n", round());
  }

  return 0;
}
