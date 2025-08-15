#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../include/utils.h"

/**
 * ランダムな整数列を生成する
 * 
 * @param arr 生成された整数列
 * @param length 生成する整数列の長さ
 */
void random_sequence(int *arr, int length) {
    // 配列を初期化
    for (int i = 0; i < length; i++) {
        arr[i] = i;
    }
    
    // 乱数の種を設定
    srand(time(NULL));
    
    // 配列をシャッフル
    for (int i = length - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

/**
 * ソート済みのランダムな整数配列を生成する
 * binary_searchなどのテスト用途向け
 * 
 * @param arr 生成された整数配列
 * @param length 生成する配列の長さ
 * @param min_val 最小値
 * @param max_val 最大値
 */
void sorted_random_array(int *arr, int length, int min_val, int max_val) {
    if (length <= 0) return;
    
    srand(time(0));
    
    for (int i = 0; i < length; i++) {
        arr[i] = min_val + rand() % (max_val - min_val + 1);
    }
    
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}