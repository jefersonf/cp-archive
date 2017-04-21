#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

const int N = 100100;

int a[N], h[N], p[N];

bool compareHeight(int i, int j) {
  return h[i] < h[j];
}

int main() {

  ios_base::sync_with_stdio(0);
  //cin.tie(0);

  int i, j, n;
  while (cin >> n)
  {
    for (i = 0; i < n; ++i) {
      cin >> a[i];
    }

    i = 0;
    j = 1;
    while (i < n) {
      h[j] = a[i];
      p[j] = j;
      j += 1;
      while (i + 1 < n && a[i] == a[i+1]) i++;
      i++;
    }

    h[0] = h[j] = 0;
    sort(p + 1, p + j, compareHeight);

    int t = 1, resp = 1;
    for (i = 1; i < j; ++i) {
      int A = 0, V = 0;
      A += (h[p[i]] > h[p[i] - 1]);
      A += (h[p[i]] > h[p[i] + 1]);
      V += (h[p[i]] < h[p[i] - 1]);
      V += (h[p[i]] < h[p[i] + 1]);
      if (A == 2) t--;
      if (V == 2) t++;
      resp = max(resp, t);
    }

    cout << resp << "\n";
  }

  return 0;
}
