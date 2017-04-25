#include <cstdio>
using namespace std;

const int N = 3010;

bool isp[N];
int np, primes[N];

void sieve() {
  int i, j;
  np = 0;
  primes[np++] = 2;
  for (i = 3; i < N; i += 2)
    isp[i] = true;
  for (i = 3; i < N; i += 2) {
    if (isp[i]) {
      for (j = i*i; j < N; j += i) isp[j] = false;
      primes[np++] = i;
    }
  }
}

int main() {

  sieve();

  int i, j, n;
  scanf("%d", &n);

  int resp = 0;
  for (i = 6; i <= n; ++i) {
    int d = 0;
    for (j = 0; j < np; ++j) {
      d += (i % primes[j] == 0);
    }
    if (d == 2) resp++;
  }

  printf("%d\n", resp);
  return 0;
}
