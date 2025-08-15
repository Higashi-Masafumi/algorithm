#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../include/utils.h"

/**
 * 最小素因数（Smallest Prime Factor）を計算する
 * エラトステネスの篩を応用して、各数の最小素因数を事前計算
 * 時間複雑度: O(n log log n)
 * 
 * @param n 上限値
 * @param spf 最小素因数を格納する配列（出力）
 */
void spf_calc(int n, int *spf) {
    // 初期化
    for (int i = 0; i <= n; i++) {
        spf[i] = i;  // 初期値は自分自身
    }

    int i = 2;
    // エラトステネスの篩を応用
    while (i*i <= n) {
        if (spf[i] == i) {
            int j = 2*i;
            // iの倍数の最小素因数をiに設定
            while (j <= n) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
                j += i;
            }
        }
        i++;
    }
}

/**
 * 素因数分解
 * 
 * @param n 素因数分解する数
 * @param spf 最小素因数を格納する配列
 */
void prime_factorization(int n, int *spf) {
    while (n > 1) {
        printf("%d ", spf[n]);
        n /= spf[n];    
    }
}

int main() {
    int n = random_number();
    printf("n: %d\n", n);
    int *spf = (int *)malloc((n+1) * sizeof(int));
    if (spf == NULL) {
        printf("メモリ割り当てに失敗しました\n");
        return 1;
    }
    spf_calc(n, spf); // 最小素因数を計算
    prime_factorization(n, spf); // 素因数分解
    printf("\n");
    free(spf);
    return 0;
}