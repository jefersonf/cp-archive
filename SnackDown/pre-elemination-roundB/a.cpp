#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int N;
bool used[110];

int main() {

  freopen("tc.in", "r", stdin);

  int i, T;
  cin >> T;

  string str;
  while (T--) {
    cin >> str;
    int m = 0;
    N = str.length();
    for (i = 0; i < N; ++i) {
      if (str[i]=='m') m++;
      used[i] = false;
    }
    int s = N - m;
    if (s > 2*m) {
      cout << "snakes\n";
    } else {
      
      vector < pair<int, int> > t;
      int l = -1;
      for (i = 0; i < N; ++i) {
        if (str[i] == 'm') {
          if (l < 0) l = i;
        } else {
          if (l >= 0) {
            t.push_back( make_pair(l, i-1) );
            l = -1;
          }
        }
      }

      if (l > 0) {
        t.push_back( make_pair(l, l) );
      }

      int p, q, x;
      for (i = 1; i < (int) t.size(); ++i) {
        p = t[i-1].second - t[i-1].first + 1;
        q = t[i].second - t[i].first + 1;
        x = t[i].first - t[i-1].second - 1;
        if (used[t[i-1].second]) {
          used[t[i].first] = true;
          s -= 1;
        } else {
          if (x == 1) {
            s -= 1;
            if (p >= 2 && q >= 2) {
              used[t[i-1].second] = true;
              used[t[i].first] = true;
            } else if (p >= 2) {
              used[t[i-1].second] = true;
            } else if (q >= 2) {
              used[t[i].first] = true;
            }
          } else {
            used[t[i-1].second] = true;
            used[t[i].first] = true;
            s -= 2;
          }
        }
      }

      int u = t.size();
      if (u > 0) {

        if (!used[t[0].first] && t[0].first > 0) {
          used[t[0].first] = true;
          s--;
        }
        if (!used[t[u - 1].second] && t[u - 1].second < N - 1) {
            used[t[u - 1].second] = true;
            s--;
          }
        }

        if (s < m) {
          cout << "mongooses\n";
        } else if (s > m) {
          cout << "snakes\n";
        } else {
          cout << "tie\n";
        }
    }
  }

  return 0;
}
