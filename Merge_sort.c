#include <stdio.h>
#include <time.h>
#define max 1000

void merge_divide(int arr[max], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        merge_divide(arr, low, mid);
        merge_divide(arr, mid + 1, high);
        merge_conquer(arr, low, mid, high);
    }
}

void merge_conquer(int arr[max], int low, int mid, int high) {
    int i = low, k = 0, j = mid + 1;
    int n = high - low + 1;
    int c[n];

    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            c[k++] = arr[i++];
        } else {
            c[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        c[k++] = arr[i++];
    }

    while (j <= high) {
        c[k++] = arr[j++];
    }

    for (int x = 0; x < n; x++) {
        arr[low + x] = c[x];
    }
}

int main() {
    int arr[max];
    for(int i=0;i<1000;i++){
        arr[i]=rand();
    }

    double start=clock();

    merge_divide(arr, 0, 999);

    double end=clock();

    for (int i = 0; i < 1000; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nTime: %f\n", (end - start) / CLOCKS_PER_SEC);

    return 0;
}
