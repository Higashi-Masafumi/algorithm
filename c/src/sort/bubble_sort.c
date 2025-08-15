#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "../../include/utils.h"

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubble_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        bool swapped = false;
        
        for (int j = 0; j < size - i - 1; j++) {
            // もし、arr[j]がarr[j + 1]より大きい場合は、交換する
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }

        // もし、swappedがfalseの場合は、ソートが完了しているので、ループを抜ける
        if (!swapped) {
            break;
        }
    }
}

double measure_time(int arr[], int size) {
    clock_t start = clock();
    bubble_sort(arr, size);
    clock_t end = clock();
    
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

int main() {
    const int size = 10;
    int arr[size];
    
    random_sequence(arr, size);
    
    printf("Original array: ");
    print_array(arr, size);
    
    double time_taken = measure_time(arr, size);
    
    printf("Sorted array: ");
    print_array(arr, size);
    printf("Time taken: %.6f seconds\n", time_taken);
    
    return 0;
}