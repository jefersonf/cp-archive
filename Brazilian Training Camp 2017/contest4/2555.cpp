#include <iostream>
#include <set>
using namespace std;

int pwr(int a, int n) {
  if (n == 0) return 1;
  if (n & 1) return a * pwr(a, n - 1);
  int b = pwr(a, n/2);
  return b*b;
}

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s;
  cin >> s;

  set <string> W;
  int len = 0;

  do {
    W.clear();
    len += 1;
    for (int i = 0; i < ((int) s.size()) - len + 1; ++i) {
      W.insert(s.substr(i, len));
    }
  } while (W.size() == pwr(2, len));

  cout << len << '\n';
  return 0;
}
