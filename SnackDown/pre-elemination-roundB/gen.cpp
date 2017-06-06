#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int main() {

  freopen("tc.in", "w", stdout);

  int T = 4;
  cout << T << '\n';
  while (T--) {
    int n = 500, M = 1000000;
    cout << n <<" "<< n <<'\n';
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cout << (1 + rand() % M) << " ";
      } cout << "\n";
    }
  }

  return 0;
}
