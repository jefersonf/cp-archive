#include <iostream>
#include <stack>
#include <fstream>
using namespace std;

stack <char> S;

int main(){
	
	freopen("brackets.in", "rt", stdin);
	freopen("brackets.out", "wt", stdout);

	int n;
	string p;
	while (getline(cin, p)) {
		n = p.length();
		for (int i = 0; i < n; ++i) {
			if (p[i] == '(' || p[i] == '[') {
				S.push(p[i]);
			} else if (p[i] == ']' || p[i] == ')') {
				if (!S.empty()) {
					char top = S.top();
					if (p[i] == ')' && top == '(') {
						S.pop();
					} else if (p[i] == ']' && top == '[') {
						S.pop();
					} else {
						S.push(p[i]);
					}
				} else {
					S.push(p[i]);
				}
			}
		}

		if (S.empty()) {
			puts("YES");
		} else {
			puts("NO");
			while (!S.empty()) S.pop();
		}
	}

	return 0;
}