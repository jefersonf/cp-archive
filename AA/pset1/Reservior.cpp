#include <bits/stdc++.h>
using namespace std;

const int MN = 1010;

int id, N, M;
char t[MN][MN];

bool overflow(int i, int j) {
  if ((i == N-1) || (j == 0) || (j == M-1)) return true;
  if (t[i+1][j] == 'A') return true;
  if (t[i][j-1] == 'A') return true;
  if (t[i][j+1] == 'A') return true;
  return false;
}

bool falling(int i, int j) {
  if (i==N-1) return false;
  return t[i+1][j] != 'B';
}

bool solve() {
  int i, j;
  for (i = 0; i < N; ++i) {
    for (j = 0; j < M; ++j) {
      if (t[i][j] == 'W') {
        if (overflow(i, j)) return false;
      } else if (t[i][j] == 'B') {
        if (falling(i, j)) return false;
      }
    }
  }
  return true;
}

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  freopen("test.in", "r", stdin);

  int i, T;
  cin >> T;
  while (T--)
  {
    cin >> N >> M;
    for (i = 0; i < N; ++i) cin >> t[i];
    solve() ? cout << "yes" : cout << "no";
    cout << '\n';
  }

  return 0;
}
