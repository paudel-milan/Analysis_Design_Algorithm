#include <stdio.h>
#include<time.h>
#include<stdlib.h>

#define MAX 1000


void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


int partition(int arr[MAX], int low, int high) {
    int pivot = arr[high]; 
    int i = (low - 1);

    for (int j = low; j < high; j++) {

        if (arr[j] <= pivot) {
            i++; 
            swap(&arr[i], &arr[j]); 
        }
    }
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
}


void quick_sort(int arr[MAX], int low, int high) {
    if (low < high) {

        int pIdx = partition(arr, low, high);


        quick_sort(arr, low, pIdx - 1); 
        quick_sort(arr, pIdx + 1, high);
    }
}


int main() {
    int arr[MAX];
    for(int i=0;i<1000;i++){
        arr[i]=rand()%1000;
    }

    clock_t start=clock();

    quick_sort(arr, 0, 1000);

    clock_t end=clock();

    for (int i = 0; i < 1000; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nTime: %.10f\n", ((double)(end - start) / CLOCKS_PER_SEC));

    return 0;
}

