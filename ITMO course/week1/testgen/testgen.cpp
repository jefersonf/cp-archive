#include <iostream>
#include <fstream>
using namespace std;

int primes[] = {2, 3, 5, 7, 11, 13, 17};

int main() {

  freopen("testgen.in", "rt", stdin);
  freopen("testgen.out", "wt", stdout);

	int K;
	cin >> K;

	int p = 2, mx = 2;
	for (int i = K; i > 1; --i) {
		int tmp = i, d = 1;
		for (int j = 0; j < 7 && primes[j] <= i; ++j) {
			int c = 0;
			while (tmp % primes[j] == 0) {
				tmp /= primes[j];
				c++;
			}
			d *= (c + 1);
		}
		if (d >= mx) {
			mx = d;
			p = i;
		}
	}

	cout << (K - p + 1) << endl;
	return 0;
}
