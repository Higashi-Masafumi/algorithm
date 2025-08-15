#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

/**
 * エラトステネスの篩でn以下の素数を表示する
 * 時間複雑度: O(n log log n)
 * 
 * @param n 上限値
 */
void print_primes_up_to(int n) {
    bool *is_prime = (bool *)malloc((n + 1) * sizeof(bool));
    
    // 初期化: 2以上を素数としてマーク
    for (int i = 2; i <= n; i++) {
        is_prime[i] = true;
    }
    is_prime[0] = is_prime[1] = false;
    
    // エラトステネスの篩
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            // iの倍数を非素数としてマーク
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    
    // 素数を表示
    printf("%d以下の素数: ", n);
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
    
    free(is_prime);
}

int main() {
    int n = 100;
    
    clock_t start, end;
    double cpu_time_used;
    
    start = clock();
    print_primes_up_to(n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    printf("実行時間: %f 秒\n", cpu_time_used);
    
    return 0;
}
