#include <iostream>
#include <fstream>
using namespace std;

int main() {

	freopen("aplusbb.in", "rt", stdin);
	freopen("aplusbb.out", "wt", stdout);

	long long int a, b;
	cin >> a >> b;
	cout << (a+b*b) << endl;
	return 0;
}