#include <bits/stdc++.h>
using namespace std;

int main() {

  freopen("test.in", "r", stdin);

  int i, N, R;
  string s;
  cin >> R;

  while (R--) {
    cin >> N >> s;
    int h = 0;
    bool valid = true;
    for (i = 0; i <= N; ++i) {
      if (s[i] == 'H') {
        if (h > 0) valid = false;
        h++;
      } else if (s[i] == 'T') {
        if (h > 0) h = 0;
        else if (h == 0) valid = false;
      }
    }

    if (valid && h == 0) {
      cout << "Valid\n";
    } else {
      cout << "Invalid\n";
    }
  }

  return 0;
}
