#include <iostream>
using namespace std;

#define INF 1000000000

void merge(int A[], int p, int m, int r) {
    int n1 = m - p + 1;
    int n2 = r - m;
    int L[n1 + 1], R[n2 + 1];
    int i, j;
    for (i = 1; i <= n1; ++i)
	L[i] = A[p + i - 1];
    for (j = 1; j <= n2; ++j)
	R[j] = A[m + j];
    L[n1 + 1] = INF; 
    R[n2 + 1] = INF;
    i = 1;
    j = 1;
    int k;
    for (k = p; k <= r; ++k) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i = i + 1;
        } else {
    	    A[k] = R[j];
	    j = j + 1;
        }
    }
  
}

void mergeSort(int A[], int i, int j) {
    if (i < j) {
        int m = (i + j) / 2;
        mergeSort(A, i, m);
	    mergeSort(A, m + 1, j);
	    merge(A, i, m, j);
    }
}

int main() {
    return 0;
}
