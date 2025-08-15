#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../include/random_sequence.h"

/**
 * スライディングウィンドウを使って最大部分配列の和を求める
 * 時間複雑度: O(n)
 * 
 * @param arr 入力配列
 * @param n 配列の長さ
 * @param m 部分配列の長さ
 * @param start_index 最大和を持つ部分配列の開始インデックス（出力）
 * @return 最大部分配列の和
 */
int find_max_subarray_twopointer(int *arr, int n, int m, int *start_index) {
    
    // 最初の部分配列（長さm）の和を計算
    int current_sum = 0;
    for (int i = 0; i < m; i++) {
        current_sum += arr[i];
    }
    
    int max_sum = current_sum;
    int best_start = 0;
    
    // スライディングウィンドウで効率的に計算
    // 前の部分配列の最初の要素を引いて、新しい要素を足す
    for (int i = 1; i <= n - m; i++) {
        current_sum = current_sum - arr[i-1] + arr[i+m-1];
        
        if (current_sum > max_sum) {
            max_sum = current_sum;
            best_start = i;
        }
    }
    
    *start_index = best_start;
    return max_sum;
}

int main() {
    int n = 1000000;
    int m = 100;
    int *arr = (int*)malloc(n * sizeof(int));
    int start_index;
    clock_t start, end;
    double cpu_time_used;

    random_sequence(arr, n);

    start = clock();
    int max_sum = find_max_subarray_twopointer(arr, n, m, &start_index);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Time taken: %f seconds\n", cpu_time_used);
    printf("max_sum: %d\n", max_sum);
    printf("start_index: %d\n", start_index);
    
    free(arr);
    return 0;
}
