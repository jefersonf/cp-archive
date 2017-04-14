#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

const int N = 1000100;

long long Stack[N];
int top = 0;

inline void Push(long long x) { Stack[top++] = x; }
inline long long Top() { return Stack[top-1]; }
inline void Pop() { if (top > 0) top--; }
inline bool Empty() { return top == 0; }

int main() {

	freopen("postfix.in", "rt", stdin);
	freopen("postfix.out", "wt", stdout);

	string x; long long a, b;
	while (cin >> x) {
		if (x == "+") {
			b = Top(); Pop();
			a = Top(); Pop();
			Push(a + b);
		} else if (x == "-") {
			b = Top(); Pop();
			a = Top(); Pop();
			Push(a - b);
		} else if (x == "*") {
			b = Top(); Pop();
			a = Top(); Pop();
			Push(a * b);
		} else {
			Push(atol(x.c_str()));
		}
	}

	printf("%lld\n", Top());
	return 0;
}