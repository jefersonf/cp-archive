
/* Overall complexity: O(n²)
 * where n is the number of elements to be ordered
 */

void bubble_sort(int arr[], int n) {
    bool swapped = true;
    int i, j = 0;
    while (swapped) {
        swapped = false; j++;
        for (i = 0; i < n - j; i++)
            if (arr[i] > arr[i + 1]) {
                arr[i] ^= arr[i + 1]; arr[i + 1] ^= arr[i]; arr[i] ^= arr[i + 1];
                swapped = true;
            }
    }
}
