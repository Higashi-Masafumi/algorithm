#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../include/random_sequence.h"


int find_max_subarray_naive(int *arr, int n, int m, int *start_index) {
    int max_sum = 0;
    int best_start = 0;
    
    for (int i = 0; i < n; i++) {
        max_sum += arr[i];
    }
    best_start = 0;
    
    for (int i = 0; i <= n - m; i++) {
        int current_sum = 0;
        
        for (int j = i; j < i + m; j++) {
            current_sum += arr[j];
        }
        
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
    int max_sum = find_max_subarray_naive(arr, n, m, &start_index);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Time taken: %f seconds\n", cpu_time_used);
    printf("max_sum: %d\n", max_sum);
    printf("start_index: %d\n", start_index);
    
    free(arr);
    return 0;
}