
/* Overall complexity: O(d(n + k)) ~ O(nk)
 * where n is the number of elements to be ordered,
 * d the number of digits and k the base of the numbers
 */

int radix_sort(int arr[], int n) {
	// maximum value in arr[]
    int i, j, aux[n], mx = arr[0];
    aux[0] = mx = arr[0];
    for (int i = 1; i < n; i++) {
        aux[i] = arr[i];
        if (arr[i] > mx) mx = arr[i];
    }
    // Do counting sort for every position/digit
    j = 1;
    while (mx % j < mx) {
        int cnt[10] = {0};
        for (i = 0; i < n; i++)
            cnt[ (arr[i]/j)%10 ]++;
        for (int i = 1; i < 10; i++)
            cnt[i] += cnt[i - 1];
        for (i = n - 1; i >= 0; i--) {
            aux[cnt[(arr[i]/j)%10] - 1] = arr[i];
            cnt[ (arr[i]/j)%10 ]--;
        }

        for (i = 0; i < n; i++) arr[i] = aux[i];
        j *= 10;
    }
}
