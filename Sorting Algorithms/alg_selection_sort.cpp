
/* Overall complexity: O(n²)
 * where n is the number of elements to be ordered
 */

int selection_sort(int arr[], int n) {
    int i, j, key;
    for (i = 0; i < n; i++) {
        key = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[key]) key = j;
        if (key != i) { // swap them
            arr[key] ^= arr[i]; arr[i] ^= arr[key]; arr[key] ^= arr[i];
        }
    }
}
