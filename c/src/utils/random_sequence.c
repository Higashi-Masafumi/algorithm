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