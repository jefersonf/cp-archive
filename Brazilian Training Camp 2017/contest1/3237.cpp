#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int N = 1000100;

bool isPrime[N];
int dist[N];
int seen[N];

void sieve() {
  isPrime[2] = true;
  int i, j;
  for (i = 3; i < N; i += 2)
    isPrime[i] = true;
  for (i = 3; i < N; i += 2) {
    if (isPrime[i]) {
      for (j = i+i; j < N; j += i)
        isPrime[j] = false;
    }
  }
}

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  sieve();

  int i, n, m, T;
  string s, t;

  cin >> T;

  m = 1;
  while (T--) {
    cin >> n >> s;

    deque <string> qu;
    qu.push_back(s);
    dist[stoi(s)] = 0;

    int x, y, resp = 0;
    bool found = false;
    while (!found && !qu.empty())
    {
      t = qu.front();
      qu.pop_front();
      x = stoi(t);

      if (seen[x] >= m) continue;
      seen[x] = m;

      if (isPrime[x]) {
        resp = dist[x];
        found = true;
        break;
      }

      for (i = ((int) t.size()) - 1; i >= 0; --i)
      {
        string r = t;
        if (t[i] > '0') {
          r[i]--;
        } else {
          r[i] = '9';
        }

        y = stoi(r);
        if (seen[y] < m)
        {
          dist[y] = dist[x] + 1;
          if (isPrime[y])
          {
            resp = dist[y];
            found = true;
            break;
          }
          qu.push_back(r);
        }

        r = t;
        if (t[i] < '9') {
          r[i]++;
        } else {
          r[i] = '0';
        }

        y = stoi(r);
        if (seen[y] < m)
        {
          dist[y] = dist[x] + 1;
          if (isPrime[y])
          {
            resp = dist[y];
            found = true;
            break;
          }
          qu.push_back(r);
        }
      }
    }

    cout << resp << "\n";
    m += 1;
  }

  return 0;
}
