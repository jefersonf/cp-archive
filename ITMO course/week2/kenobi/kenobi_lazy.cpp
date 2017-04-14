#include <cstdio>
#include <fstream>
using namespace std;

struct Data {
	int value;
	Data* next;
	Data* prev;
	Data() {}
	Data(int x) {
		value = x;
		next = NULL;
		prev = NULL;
	}
};

Data *head, *tail, *mid;

void Print(Data *curr, bool f) {
	if (curr->next == NULL) return;
	if (f) printf(" ");
	printf("%d", curr->value);
	Print(curr->next, true);
}

void mum(int sz) {
	int k = (sz / 2);
	mid = head;
	while (k--) { mid = mid->next; }
	mid->next->prev = head;
	head->next->prev = tail->prev;
	tail->prev->next = head->next;
	head->next = mid->next;
	mid->next = tail;
	tail->prev = mid;
}

int main() {

	freopen("kenobi_gen.in", "rt", stdin);
	freopen("kenobi_gen.out", "wt", stdout);
	
	int n, x, sz, cnt;
	scanf("%d", &n);

	head = new Data(-1);
	tail = new Data(-1);
	
	head->next = tail;
	tail->prev = head;

	char cmd[5];
	sz = 0;
	cnt = 0;
	while (n--) {
		scanf("%s[^dku]", cmd);
		if (cmd[0] == 'a') {
			scanf("%d", &x);
			if (sz%2==0 && cnt&1) { mum(sz); cnt = 0; }
			else if ((sz&1) && (cnt > 0)) {
				if ((cnt % sz != 0)) {
					cnt %= sz; 
					while (cnt--) mum(sz);
				}
				cnt = 0;
			}
			tail->prev->next = new Data(x);
			tail->prev->next->next = tail;
			tail->prev->next->prev = tail->prev;
			tail->prev = tail->prev->next;
			sz++;
		} else if (cmd[0] == 't') {
			if (sz%2==0 && cnt&1) { mum(sz); cnt = 0; }
			else if ((sz&1) && (cnt > 0)) {
				if ((cnt % sz != 0)) {
					cnt %= sz;
					while (cnt--) mum(sz);
				}
				cnt = 0;
			}
			tail->prev->prev->next = tail;
			tail->prev = tail->prev->prev;
			sz--;
		} else if (sz > 1) {
			cnt++;
		}
	}

	if (sz%2==0 && cnt&1) { mum(sz); }
	else if ((sz&1) && (cnt > 0)) {
		if ((cnt % sz != 0)) {
			cnt %= sz;
			while (cnt--) { mum(sz); }
		}
		cnt = 0;
	}

	printf("%d\n", sz);
	if (sz > 0) {
		Print(head->next, false);
		printf("\n");
	}

	return 0;
}

/*

#include <cstdio>
#include <deque>
#include <fstream>
using namespace std;

int p = 0;
deque <int> d[2];

int main() {

	freopen("kenobi_gen.in", "rt", stdin);
	freopen("kenobi.out", "wt", stdout);
	
	int n, x, sz, L, R;
	scanf("%d", &n);

	char cmd[5];
	sz = 0;
	while (n--) {
		scanf("%s[^dku]", cmd);
		if (sz > 0) {
			if (d[p].size() < d[1-p].size()) {
				L = d[p].size();
				R = d[1-p].size();
			} else {
				L = d[1-p].size();
				R = d[p].size();
			}

			if (sz % 2 == 0) {
				if (L > R) {
					d[p].push_back(d[1-p].front());
					d[1-p].pop_front();
				} else if (L < R) {
					d[1-p].push_back(d[p].front());
					d[p].pop_front();
				}
			} else {
				if (L > R) {
					d[p].push_front(d[1-p].back());
					d[1-p].pop_back();
				} else if (L < R) {
					d[1-p].push_front(d[p].back());
					d[p].pop_back();
				}
			}
		} else p = 0;

		if (cmd[0] == 'a') {
			scanf("%d", &x);
			d[p].push_back(x);
			sz++;
		} else if (cmd[0] == 't') {
			d[p].pop_back();
			sz--;
		} else if (sz > 1) {
			p ^= 1;
		}
	}

	if (sz > 0) {
		if (d[p].size() < d[1-p].size()) {
			L = d[p].size();
			R = d[1-p].size();
		} else {
			L = d[1-p].size();
			R = d[p].size();
		}
		if (sz % 2 == 0) {
			if (L > R) {
				d[p].push_back(d[1-p].front());
				d[1-p].pop_front();
			} else if (L < R) {
				d[1-p].push_back(d[p].front());
				d[p].pop_front();
			}
		} else {
			if (R < L) {
				d[p].push_front(d[1-p].back());
				d[1-p].pop_back();
			} else if (R > L) {
				d[1-p].push_front(d[p].back());
				d[p].pop_back();
			}
		}
	}

	printf("%d\n", sz);

	bool f = false;
	while (!d[1-p].empty()) {
		if (f) printf(" ");
		f = true;
		printf("%d", d[1-p].front());
		d[1-p].pop_front();
	}

	while (!d[p].empty()) {
		if (f) printf(" ");
		f = true;
		printf("%d", d[p].front());
		d[p].pop_front();
	}

	printf("\n");
	return 0;
}



*/



/*
 Second try

 #include <cstdio>
#include <deque>
#include <fstream>
using namespace std;

int p = 1, k = 0;
deque <int> d[2];

deque <int>::iterator it;

void mos() {
	bool f = false;
	it = d[0].begin();
	printf("{");
	while (it != d[0].end()) {
		if (f) printf(" ");
		f = true;
		printf("%d", (*it));
		it++;
	}

	printf("} {");
	it = d[1].begin();
	while (it != d[1].end()) {
		if (f) printf(" ");	
		f = true;
		printf("%d", (*it));
		it++;
	}

	printf("}\n");
}

int main() {

	freopen("kenobi_gen.in", "rt", stdin);
	freopen("kenobi.out", "wt", stdout);
	
	int n, x, sz, L, R;
	scanf("%d", &n);

	char cmd[5];
	sz = 0;
	while (n--) {
		scanf("%s[^dku]", cmd);
		// printf("######################################### p = %d\n", p);
		if (sz > 1) {
			if (d[p].size() < d[1-p].size()) {
				d[p].push_front(d[1-p].back());
				d[1-p].pop_back();
				// printf("Balanciei!\n");
				// mos();
			} else if (d[p].size() > d[1-p].size() + 1) {
				if (p == 0) {
					if (k %2==0) {
						d[1-p].push_front(d[p].back());
						d[p].pop_back();
						//printf("Pequei do final da esq e coloquei na frente da dir!\n");
					} else {
						d[1-p].push_back(d[p].front());
						d[p].pop_front();
					}
					//k ^= 1;
						// printf("Pequei da frente da dir e coloquei no final da esq!\n");
				} else {
						// printf("Pequei da frente da dir e coloquei no final da esq!\n");
					if (k & 1) {
						d[1-p].push_back(d[p].front());
						d[p].pop_front();
					} else {
						d[1-p].push_front(d[p].back());
						d[p].pop_back();
						//printf("Pequei do final da esq e coloquei na frente da dir!\n");
					}
						//k ^= 1;
				}
				// mos();
			}
		} else if (sz == 1) {
			if (p == 0) {
				p = 1;
				k = 0;
				d[p].push_front(d[1-p].back());
				d[1-p].pop_back();
			}
		} else p = 1, k = 0;

		if (cmd[0] == 'a') {
			scanf("%d", &x);
			d[p].push_back(x);
			sz++;
			// printf("Coloquei!\n");
		} else if (cmd[0] == 't') {
			d[p].pop_back();
			// printf("Tirei!\n");
			sz--;
		} else {
			// printf("MOm!\n");
			p ^= 1;
			k++;
		}

		// mos();
	}

	if (sz > 1) {
		if (d[p].size() < d[1-p].size()) {
			d[p].push_front(d[1-p].back());
			d[1-p].pop_back();
			// printf("Balanciei!\n");
			// mos();
		} else if (d[p].size() > d[1-p].size() + 1) {
			if (p == 0) {
				if (k %2==0) {
					d[1-p].push_front(d[p].back());
					d[p].pop_back();
					//printf("Pequei do final da esq e coloquei na frente da dir!\n");
				} else {
					d[1-p].push_back(d[p].front());
					d[p].pop_front();
				}
					// printf("Pequei da frente da dir e coloquei no final da esq!\n");
			} else {
					// printf("Pequei da frente da dir e coloquei no final da esq!\n");
				if (k & 1) {
					d[1-p].push_back(d[p].front());
					d[p].pop_front();
				} else {
					d[1-p].push_front(d[p].back());
					d[p].pop_back();
					//printf("Pequei do final da esq e coloquei na frente da dir!\n");
				}
			}
			// mos();
		}
	} else if (sz == 1) {
		if (p == 0) {
			p = 1;
			d[p].push_front(d[1-p].back());
			d[1-p].pop_back();
		}
	} else p = 1;

	printf("%d\n", sz);

	bool f = false;
	while (!d[1-p].empty()) {
		if (f) printf(" ");
		f = true;
		printf("%d", d[1-p].front());
		d[1-p].pop_front();
	}
	printf("/");
	while (!d[p].empty()) {
		if (f) printf(" ");	
		f = true;
		printf("%d", d[p].front());
		d[p].pop_front();
	}

	printf("\n");
	return 0;
}





*/