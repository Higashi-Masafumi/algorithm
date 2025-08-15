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
 * 2つのソート済み配列をマージする
 * 
 * @param arr ソート対象の配列
 * @param left 左端
 * @param mid 中央
 * @param right 右端
 */
void merge(int arr[], int left, int mid, int right) {
    int left_size = mid - left + 1;
    int right_size = right - mid;
    
    int* left_arr = malloc(left_size * sizeof(int));
    int* right_arr = malloc(right_size * sizeof(int));
    
    for (int i = 0; i < left_size; i++) {
        left_arr[i] = arr[left + i];
    }
    for (int i = 0; i < right_size; i++) {
        right_arr[i] = arr[mid + 1 + i];
    }
    
    int i = 0, j = 0, k = left;
    
    // 左の配列と右の配列を比較して、小さい方をarrに追加する
    while (i < left_size && j < right_size) {
        // 左の配列の要素が右の配列の要素より小さい場合は、左の配列の要素をarrに追加する
        if (left_arr[i] <= right_arr[j]) {
            arr[k] = left_arr[i];
            i++;
        } 
        // 右の配列の要素が左の配列の要素より小さい場合は、右の配列の要素をarrに追加する
        else {
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }

    // 左の配列に残った要素がある場合は、それらを追加する
    if (i < left_size) {
        for (int l = i; l < left_size; l++) {
            arr[k] = left_arr[l];
            k++;
        }
    }

    // 右の配列に残った要素がある場合は、それらを追加する
    if (j < right_size) {
        for (int l = j; l < right_size; l++) {
            arr[k] = right_arr[l];
            k++;
        }
    }
    
    free(left_arr);
    free(right_arr);
}

/**
 * マージソートの再帰版
 * 
 * @param arr ソート対象の配列
 * @param left 左端
 * @param right 右端
 */
void merge_sort_recursive(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        merge_sort_recursive(arr, left, mid);
        merge_sort_recursive(arr, mid + 1, right);
        
        merge(arr, left, mid, right);
    }
}

/**
 * マージソート
 * 
 * @param arr ソート対象の配列
 * @param size 配列のサイズ
 */
void merge_sort(int arr[], int size) {
    merge_sort_recursive(arr, 0, size - 1);
}

double measure_time(int arr[], int size) {
    clock_t start = clock();
    merge_sort(arr, size);
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