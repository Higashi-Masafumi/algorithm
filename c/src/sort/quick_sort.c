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
 * 2つの値を交換する
 * 
 * @param a 値1
 * @param b 値2
 */
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * パーティションを作成する
 * 
 * @param arr ソート対象の配列
 * @param low 探索範囲の左端
 * @param high 探索範囲の右端
 * @return パーティションの位置
 */
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    // iはpivotより小さい値のインデックス
    // jは現在見ている値のインデックス
    for (int j = low; j < high; j++) {
        // もし、現在見ている値がpivotより小さい場合は、iを1つ進めて、その値と現在見ている値を交換する
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

/**
 * クイックソートの再帰版
 * 
 * @param arr ソート対象の配列
 * @param low 探索範囲の左端
 * @param high 探索範囲の右端
 */
void quick_sort_recursive(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        // partitionはpivotを基準として、pivotより小さい値を左に、pivotより大きい値を右に分ける
        // その後、再帰的に左と右に対して同じ操作を行う
        // これを繰り返すことで、配列がソートされる
        quick_sort_recursive(arr, low, pi - 1);
        quick_sort_recursive(arr, pi + 1, high);
    }
}

/**
 * クイックソート
 * 
 * @param arr ソート対象の配列
 * @param size 配列のサイズ
 */
void quick_sort(int arr[], int size) {
    quick_sort_recursive(arr, 0, size - 1);
}

double measure_time(int arr[], int size) {
    clock_t start = clock();
    /*
    クイックソートの計算量はO(n log n)
    つまりノード数がnの時合計でソートにかかる計算量はO(n log n)
    */
    quick_sort(arr, size);
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
