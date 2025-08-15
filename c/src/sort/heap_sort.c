#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../include/utils.h"
#include "../../include/heap.h"

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void heap_sort(int arr[], int size) {
    MaxHeap* heap = heap_create(size);
    
    for (int i = 0; i < size; i++) {
        heap_insert(heap, arr[i]);
    }
    
    for (int i = size - 1; i >= 0; i--) {
        arr[i] = heap_extract_max(heap);
    }
    
    heap_destroy(heap);
}

double measure_time(int arr[], int size) {
    clock_t start = clock();
    heap_sort(arr, size);
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