
/* Overall complexity: O(n²)
 * where n is the number of elements to be ordered
 */

int insertion_sort(int arr[], int n) {
    int i, j;
    for (int i = 1; i < n; i++) {
        j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            // swap them
            arr[j - 1] ^= arr[j]; arr[j] ^= arr[j - 1]; arr[j - 1] ^= arr[j];
            j -= 1;
        }
    }
}
