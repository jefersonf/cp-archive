#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 310;
const int MAXP = 10;

ll P[MAXP];
int N, M, X, Y;
ll dp[MAXN][MAXN];
string corda;

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a%b);
}

void init() {
  int i;
  for (i = 1,  P[0] = 1LL; i < 10; ++i) {
    P[i] = P[i-1] * 10LL;
  }
}

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  freopen("test.in", "r", stdin);
  init();

  int T;
  cin >> T;
  while (T--)
  {
      cin >> N;
      cin >> corda;
      cin >> M >> X >> Y;
      int i = 0, j;
      int len = corda.length();
      while (i < len && corda[i] == '0') i++;
      corda = corda.substr(i);
      reverse(corda.begin(), corda.end());
      N -= i;

      dp[0][0] = (ll)(corda[i]-'0');
      for (i = 1; i < M; ++i) {
        dp[0][i] = dp[0][i-1] + (ll)(corda[i]-'0') * P[i];
      }

      for (i = 1; i < N; ++i) {
        for (j = i; j < min(i + M - 1, N); ++j) {
          dp[i][j] = dp[i-1][j] / P[i % M];
        }
        dp[i][i+M-1] = dp[i][i+M-2] + (ll)(corda[(i + M) % N]-'0') * P[M-1];
      }



      cout << resp << '\n';
  }

  return 0;
}
