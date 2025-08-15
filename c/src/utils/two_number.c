#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../include/utils.h"

/**
 * 二つの整数を生成する
 * 
 * @param a 生成された整数
 * @param b 生成された整数
 * @param min_val 最小値
 * @param max_val 最大値
 */
void generate_two_random_numbers(int *a, int *b) {
    srand(time(NULL));
    
    *a = rand() % 1000000;
    *b = rand() % 1000000;
}