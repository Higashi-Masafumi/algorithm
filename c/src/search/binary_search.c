#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../include/utils.h"

/**
 * 二分探索のイテレーション版
 * 
 * @param arr 探索対象の配列
 * @param size 配列のサイズ
 * @param target 探索する値
 * @return 探索結果のインデックス
 */
int binary_search_iterative(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        
        if (arr[mid] == target) {
            return mid;
        }
        
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1;
}

/**
 * 二分探索の再帰版
 * 
 * @param arr 探索対象の配列
 * @param left 探索範囲の左端
 * @param right 探索範囲の右端
 * @param target 探索する値
 * @return 探索結果のインデックス
 */
int binary_search_recursive(int arr[], int left, int right, int target) {
    if (left > right) {
        return -1;
    }
    
    int mid = (left + right) / 2;
    
    if (arr[mid] == target) {
        return mid;
    }
    
    if (arr[mid] < target) {
        return binary_search_recursive(arr, mid + 1, right, target);
    } else {
        return binary_search_recursive(arr, left, mid - 1, target);
    }
}

void print_array(int arr[], int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    const int size = 10;
    int arr[size];
    
    sorted_random_array(arr, size, 1, 50);
    print_array(arr, size);
    
    srand(time(NULL));
    int random_index = rand() % size;
    int target = arr[random_index];
    printf("Searching for: %d (originally at index %d)\n", target, random_index);
    
    int result_iterative = binary_search_iterative(arr, size, target);
    int result_recursive = binary_search_recursive(arr, 0, size - 1, target);
    
    printf("Iterative result: ");
    if (result_iterative != -1) {
        printf("Found at index %d\n", result_iterative);
    } else {
        printf("Not found\n");
    }
    
    printf("Recursive result: ");
    if (result_recursive != -1) {
        printf("Found at index %d\n", result_recursive);
    } else {
        printf("Not found\n");
    }
    
    int not_found = 999;
    printf("\nSearching for non-existent value: %d\n", not_found);
    result_iterative = binary_search_iterative(arr, size, not_found);
    result_recursive = binary_search_recursive(arr, 0, size - 1, not_found);
    
    printf("Iterative result: %s\n", result_iterative == -1 ? "Not found" : "Found");
    printf("Recursive result: %s\n", result_recursive == -1 ? "Not found" : "Found");
    
    return 0;
}