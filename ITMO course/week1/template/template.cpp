#include <bits/stdc++.h>
using namespace std;

int myaux[3];
map <char, pair<int, int> > mymapa;
vector <string> mylangs;
vector <string> mycode;
vector <int> tempo;

bool fun(char c) {
	int v = ((int)c);
	return (v < 32) || (v > 126);
}

bool mycmp(int i, int j) { return tempo[i] < tempo[j]; }

int main() {

	freopen("template.in", "rb", stdin);
	freopen("template.out", "wb", stdout);

	string row;

	int i, j, k, W, H;
	cin >> W >> H;
	cin.ignore();
	cin.ignore();
	for (i = H; i > 0; --i) {
		getline(cin, row);
		for (j = 1; j <= W; ++j) {
			mymapa[row[j-1]] = make_pair(j, i);
		}
	}

	string all = "";
	char c;
	while ((c = getchar()) != EOF) { all += c; }

	int sz = (int) all.size();

	string wt = "";
	i = 0;
	while (i < sz) {
		j = i;
		while (j < sz && fun(all[j])) j++;
		if (j - i == 4) {
			wt += ((char) 156);
		} else if (j - i == 2) {
			wt += ((char) 157);
		}
		while (j < sz && !fun(all[j])) wt += all[j], j++;
		i = j;
	}

	char tokenA = ((char) 156);
	char tokenB = ((char) 157);

	sz = wt.size();

	i = 0;
	while (i < sz) {
		while (i < sz && (wt[i] == tokenB || wt[i] == tokenA)) i++;
		j = i;
		while (j < sz && wt[j] != tokenB) j++;
		mylangs.push_back(wt.substr(i, j-i));
		row = "";
		while (j < sz && wt[j] != tokenA) {
			if (wt[j] != tokenB && !fun(wt[j])) row += wt[j];
			j++;
		}
		mycode.push_back(row);
		i = j + 1;
	}

	for (i = 0; i < (int) mylangs.size(); ++i) {
		myaux[i] = i;
		k = 0;
		for (j = 1; j < (int) mycode[i].size(); ++j) {
			k += max(abs(mymapa[mycode[i][j]].first - mymapa[mycode[i][j-1]].first), abs(mymapa[mycode[i][j]].second - mymapa[mycode[i][j-1]].second));
		}
		tempo.push_back(k);
	}

	if (mylangs.size() > 2) {
		sort(myaux, myaux + 3, mycmp);
		cout << mylangs[myaux[0]] << endl << tempo[myaux[0]];
	}

	return 0;
}
