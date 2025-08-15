#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * スキップテーブルを計算する
 * 
 * @param pattern パターン
 * @param m パターンの長さ
 * @param skip スキップテーブル
 */
void compute_skip_table(char* pattern, int m, int* skip) {
    skip[0] = -1;
    
    if (m == 1) return;
    
    skip[1] = 0;
    
    for (int i = 2; i < m; i++) {
        int j = skip[i - 1];
        
        while (j >= 0 && pattern[i - 1] != pattern[j]) {
            j = skip[j];
        }
        
        skip[i] = j + 1;
    }
}

/**
 * KMP法で文字列を検索する
 * 
 * @param text テキスト
 * @param pattern パターン
 */
void kmp_search(char* text, char* pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    
    int* skip = malloc(m * sizeof(int));
    /*
    スキップテーブルは事前にパターン同士のマッチングを行っておくことで、
    ある文字がマッチしなかった場合に、どれだけパターンを右にずらすかを決めておける
    */
    compute_skip_table(pattern, m, skip);
    
    printf("Skip table for pattern \"%s\": ", pattern);
    for (int i = 0; i < m; i++) {
        printf("%d ", skip[i]);
    }
    printf("\n");
    
    int i = 0; // text index
    int j = 0; // pattern index
    int matches = 0;
    
    while (i < n) {
        while (j >= 0 && text[i] != pattern[j]) {
            j = skip[j];
        }
        
        i++;
        j++;
        
        if (j == m) {
            printf("Pattern found at index %d\n", i - j);
            matches++;
            j = skip[j];
        }
    }
    
    if (matches == 0) {
        printf("Pattern not found\n");
    } else {
        printf("Total matches: %d\n", matches);
    }
    
    free(skip);
}


int main() {
    printf("=== KMP String Matching Algorithm ===\n\n");
    
    char text1[] = "ABABDABACDABABCABCABCABCABC";
    char pattern1[] = "ABABCABCAB";
    
    printf("Text: %s\n", text1);
    printf("Pattern: %s\n\n", pattern1);
    
    printf("KMP Search:\n");
    kmp_search(text1, pattern1);
    
    printf("\n=== Another Example ===\n");
    char text2[] = "AABAACAADAABAABA";
    char pattern2[] = "AABA";
    
    printf("Text: %s\n", text2);
    printf("Pattern: %s\n\n", pattern2);
    
    printf("KMP Search:\n");
    kmp_search(text2, pattern2);
    
    
    return 0;
}