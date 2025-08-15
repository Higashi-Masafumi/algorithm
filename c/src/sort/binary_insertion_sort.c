#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../include/utils.h"

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/**
 * 二分探索で挿入位置を探す
 * 
 * @param arr ソート対象の配列
 * @param left 探索範囲の左端
 * @param right 探索範囲の右端
 * @param key 挿入する値
 * @return 挿入位置
 */
int binary_search_position(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] <= key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return left;
}

void binary_insertion_sort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int pos = binary_search_position(arr, 0, i - 1, key);
        
        for (int j = i; j > pos; j--) {
            arr[j] = arr[j - 1];
        }
        
        arr[pos] = key;
    }
}

void insertion_sort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        
        arr[j + 1] = key;
    }
}

double measure_time_binary(int arr[], int size) {
    clock_t start = clock();
    binary_insertion_sort(arr, size);
    clock_t end = clock();
    
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

double measure_time_regular(int arr[], int size) {
    clock_t start = clock();
    insertion_sort(arr, size);
    clock_t end = clock();
    
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

void compare_performance() {
    printf("Performance comparison:\n");
    int sizes[] = {100, 1000, 5000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
    
    for (int i = 0; i < num_sizes; i++) {
        int size = sizes[i];
        
        int* arr1 = malloc(size * sizeof(int));
        int* arr2 = malloc(size * sizeof(int));
        
        random_sequence(arr1, size);
        for (int j = 0; j < size; j++) {
            arr2[j] = arr1[j];
        }
        
        double binary_time = measure_time_binary(arr1, size);
        double regular_time = measure_time_regular(arr2, size);
        
        printf("Size %d: Binary=%.6fs, Regular=%.6fs\n", 
               size, binary_time, regular_time);
        
        free(arr1);
        free(arr2);
    }
}

int main() {
    const int size = 10;
    int arr[size];
    
    random_sequence(arr, size);
    
    printf("Original array: ");
    print_array(arr, size);
    
    double time_taken = measure_time_binary(arr, size);
    
    printf("Sorted array: ");
    print_array(arr, size);
    printf("Time taken: %.6f seconds\n\n", time_taken);
    
    compare_performance();
    
    return 0;
}