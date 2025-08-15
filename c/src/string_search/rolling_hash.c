#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BASE 256
#define MOD 101

unsigned long long power(int base, int exp, int mod) {
    unsigned long long result = 1;
    for (int i = 0; i < exp; i++) {
        result = (result * base) % mod;
    }
    return result;
}

unsigned long long compute_hash(char* str, int len) {
    unsigned long long hash = 0;
    for (int i = 0; i < len; i++) {
        hash = (hash * BASE + str[i]) % MOD;
    }
    return hash;
}

int rolling_hash_search(char* text, char* pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    
    if (m > n) {
        return 0;
    }
    
    /*
    パターンのハッシュ値を計算
    テキストのハッシュ値を計算
    ハッシュ値を更新するためのhを計算
    */
    unsigned long long pattern_hash = compute_hash(pattern, m);
    unsigned long long text_hash = compute_hash(text, m);
    unsigned long long h = power(BASE, m - 1, MOD);
    
    int matches = 0;
    
    for (int i = 0; i <= n - m; i++) {
        if (pattern_hash == text_hash) {
            int j;
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    break;
                }
            }
            if (j == m) {
                printf("Pattern found at index %d\n", i);
                matches++;
            }
        }
        
        if (i < n - m) {
            text_hash = (text_hash - (text[i] * h) % MOD + MOD) % MOD;
            text_hash = (text_hash * BASE + text[i + m]) % MOD;
        }
    }
    
    return matches;
}

double measure_time(char* text, char* pattern) {
    clock_t start = clock();
    rolling_hash_search(text, pattern);
    clock_t end = clock();
    
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

int main() {
    printf("=== Rolling Hash String Matching ===\n\n");
    
    char text[] = "ABABDABACDABABCABCABCABCABC";
    char pattern[] = "ABABC";
    
    printf("Text: %s\n", text);
    printf("Pattern: %s\n\n", pattern);
    
    double time_taken = measure_time(text, pattern);
    
    int matches = rolling_hash_search(text, pattern);
    printf("\nTotal matches: %d\n", matches);
    printf("Time taken: %.6f seconds\n", time_taken);
    
    return 0;
}