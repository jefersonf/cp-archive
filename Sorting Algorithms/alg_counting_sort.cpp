
/* Overall complexity: O(n + k)
 * where n is the number of elements to be ordered
 * and k the range of input
 */

const int MAXN = 1000;

int counting_sort(int arr[], int n) {

    int i, aux[MAXN];
    int cnt[MAXN] = {0};

    for (i = 0; i < n; i++)
        cnt[arr[i]]++;

    for (i = 1; i < MAXN; i++)
        cnt[i] += cnt[i - 1];

    for (i = 0; i < n; i++) {
        aux[cnt[arr[i]] - 1] = arr[i];
        cnt[arr[i]]--;
    }

    for (i = 0; i < n; i++) arr[i] = aux[i];
}
