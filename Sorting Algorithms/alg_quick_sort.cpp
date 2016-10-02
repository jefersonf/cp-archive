
/* Overall complexity: O(n log n)
 * where n is the number of elements to be ordered.
 */
 
void quick_sort(int arr[], int l, int r) {

	int i = l, j = r;
	int pivot = arr[(i+j)/2];

	while (i <= j) {
		while (arr[i] < pivot) i++;
		while (arr[j] > pivot) j--;
		if (i <= j) {
			int tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	}

	if (l < j) quick_sort(arr, l, j);
	if (i < r) quick_sort(arr, i, r);
}
