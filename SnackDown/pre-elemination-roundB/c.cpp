#include <iostream>
#include <fstream>
using namespace std;

int main() {

  freopen("tc.in", "r", stdin);

  int T;
  cin >> T;

  while (T--)
  {
      int N;
      cin >> N;
      char sl[2][N];

      int i, j, up = 0, down = 0;
      for (i = 0; i < 2; ++i) {
        scanf("%s", sl[i]);
        for (j = 0; j < N; ++j) {
          if (sl[i][j] == '*') {
            if (i == 0) up++;
            if (i == 1) down++;
          }
        }
      }

      int resp = (up > 0 && down > 0);
      bool f1 = false, f2 = false;
      for (i = 0; i < N; ++i) {
        if (sl[0][i] == '*') {
          if (f1) {
            resp += 1;
            --i;
            f1 = f2 = false;
            continue;
          } else {
            f1 = true;
          }
        }
        if (sl[1][i] == '*') {
          if (f2) {
            resp += 1;
            --i;
            f1 = f2 = false;
          } else {
            f2 = true;
          }
        }
      }

      cout << resp << '\n';
  }

  return 0;
}
