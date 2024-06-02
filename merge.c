#include <stdio.h>

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    for (int i = 0, j = 0, k = l; k <= r; k++) {
        if (i < n1 && (j >= n2 || L[i] <= R[j])) arr[k] = L[i++];
        else arr[k] = R[j++];
    }
}

void mergesort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int n;
    printf("Enter the Size of Array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the Elements of Array:\n");
    for (int i = 0; i < n; i++){
        printf("Array[%d]: ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("\nGiven Array is: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    mergesort(arr, 0, n - 1);
    printf("\nSorted Array is: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    return 0;
}   