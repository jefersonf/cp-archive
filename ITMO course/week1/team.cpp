#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <fstream>
using namespace std;

double table[3][3], sum, ans;

void solve(int i, int mask) {
	if (i == 3) {
		ans = max(ans, sum);
		return;
	}
	for (int j = 0; j < 3; ++j) {
		if (mask & (1 << j)) continue;
		sum += table[i][j]*table[i][j];
		solve(i + 1, mask | (1 << j));
		sum -= table[i][j]*table[i][j];
	}
}

int main() {
	
	freopen("team.in", "rt", stdin);
	freopen("team.out", "wt", stdout);

	int i, j;
	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 3; ++j) {
			cin >> table[i][j];
		}
	}

	ans = 0;
	solve(0, 0);
	
	cout << fixed << setprecision(30) << sqrt(ans) << endl;
	return 0;
}