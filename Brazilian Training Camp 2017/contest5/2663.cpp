#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1000000000;
map <int, int> mp;
vector<int> v;

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  v.push_back(0);
  queue<int> qu;
  for (int i = 0; i < 10; i++) qu.push(i);
  while (!qu.empty()) {
    int t = qu.front();
    qu.pop();
    if (t > N) break;
    for (int i = ((t % 10) + 1); i < 10; ++i) {
      int x = t*10 + i;
      if (mp.count(x) == 0) {
        qu.push(x);
        v.push_back(x);
        mp[x] = 1;
      }
    }
  }

  int T, _a, _b;
  cin >> T;

  while (T--) {
    cin >> _a >> _b;
    int a = min(_a, _b);
    int b = max(_a, _b);
    int l = lower_bound(v.begin(), v.end(), a) - v.begin();
    int r = upper_bound(v.begin(), v.end(), b) - v.begin();
    cout << (r - l) << '\n';
  }

  return 0;
}
