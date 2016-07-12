#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 500;

int fsum[N], pos[N];

bool compare(int i, int j) {
    if (fsum[i] == fsum[j])
        return i < j;
    return fsum[i] > fsum[j];
}

int main() {

    int i, j, n, m, f = 0;
    while (scanf("%d %d", &n, &m) != EOF) {

        if (f) printf("\n"); else f = 1;

        memset(fsum, 0, sizeof fsum);
        memset(pos, 0, sizeof pos);

        for (i = 1; i <= n; ++i)
            for (j = 1; j <= m; ++j)
                fsum[i+j]++;

        for (int i = 1; i <= n + m; ++i)
            pos[i] = i;

        sort(pos + 1, pos + n + m + 1, compare);

        i = 1;
        j = fsum[pos[i]];
        while (fsum[pos[i]] == j) {
            printf("%d\n", pos[i]);
            i++;
        }
    }

    return 0;
}
