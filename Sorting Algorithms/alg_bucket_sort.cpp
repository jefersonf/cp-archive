
/* Overall complexity: O(n²)
 * where n is the number of elements to be ordered.
 * better for input uniformly distributed over a range.
 */

void bucket_sort(float arr[], int n) {

    vector<float> bucket[n];

    for (int i = 0; i < n; i++) {
        int id = n * arr[i];
        bucket[id].push_back(arr[i]);
    }

    for (int i = 0; i < n; i++)
        sort(bucket[i].begin(), bucket[i].end());

    int idx = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < bucket[i].size(); j++)
            arr[idx++] = bucket[i][j];
}
