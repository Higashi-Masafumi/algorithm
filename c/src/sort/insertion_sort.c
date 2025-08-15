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
 * 挿入ソート
 * 
 * @param arr ソート対象の配列
 * @param size 配列のサイズ
 */
void insertion_sort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        
        // 挿入する位置を探す
        while (j >= 0 && arr[j] > key) {
            // もし、keyがarr[j]より小さい場合は、arr[j]を1つ右にずらす
            arr[j + 1] = arr[j];
            j--;
        }
        // 挿入する位置にkeyを挿入する
        arr[j + 1] = key;
    }
}

double measure_time(int arr[], int size) {
    clock_t start = clock();
    /*
    挿入ソートの計算量はO(n^2)
    つまりノード数がnの時合計で挿入にかかる計算量はO(n^2)
    */
    insertion_sort(arr, size);
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