#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct MaxHeap {
    int* data;
    int size;
    int capacity;
} MaxHeap;

MaxHeap* heap_create(int capacity) {
    MaxHeap* heap = (MaxHeap*)malloc(sizeof(MaxHeap));
    if (!heap) return NULL;
    
    heap->data = (int*)malloc(capacity * sizeof(int));
    if (!heap->data) {
        free(heap);
        return NULL;
    }
    
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void heap_destroy(MaxHeap* heap) {
    if (heap) {
        free(heap->data);
        free(heap);
    }
}

/**
 * ヒープが空かどうかを確認する
 * 
 * @param heap ヒープ
 * @return ヒープが空かどうか
 */
bool heap_is_empty(MaxHeap* heap) {
    return heap->size == 0;
}

/**
 * ヒープが満杯かどうかを確認する
 * 
 * @param heap ヒープ
 * @return ヒープが満杯かどうか
 */
bool heap_is_full(MaxHeap* heap) {
    return heap->size == heap->capacity;
}

/**
 * 親ノードのインデックスを取得する
 * 
 * @param index 現在のノードのインデックス
 * @return 親ノードのインデックス
 */
int heap_parent(int index) {
    return (index - 1) / 2;
}

/**
 * 左の子ノードのインデックスを取得する
 * 
 * @param index 現在のノードのインデックス
 * @return 左の子ノードのインデックス
 */
int heap_left_child(int index) {
    return 2 * index + 1;
}

/**
 * 右の子ノードのインデックスを取得する
 * 
 * @param index 現在のノードのインデックス
 * @return 右の子ノードのインデックス
 */
int heap_right_child(int index) {
    return 2 * index + 2;
}

/**
 * 2つの値を交換する
 * 
 * @param a 値1
 * @param b 値2
 */
void heap_swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * ヒープを上に向かって再構築する
 * 親ノードと比較して、親ノードより大きい場合は交換する
 * 
 * @param heap ヒープ
 * @param index 現在のノードのインデックス
 */
void heapify_up(MaxHeap* heap, int index) {
    if (index == 0) return;
    
    int parent_index = heap_parent(index);
    // 親ノードより大きい場合は交換する
    if (heap->data[index] > heap->data[parent_index]) {
        heap_swap(&heap->data[index], &heap->data[parent_index]);
        heapify_up(heap, parent_index);
    }
}

/**
 * ヒープに値を挿入する
 * 
 * @param heap ヒープ
 * @param value 挿入する値
 * @return 挿入が成功したかどうか
 */
bool heap_insert(MaxHeap* heap, int value) {
    if (heap_is_full(heap)) {
        printf("Error: Heap is full\n");
        return false;
    }
    
    heap->data[heap->size] = value;
    heapify_up(heap, heap->size);
    heap->size++;
    
    return true;
}

/**
 * ヒープを下に向かって再構築する
 * 子ノードと比較して、子ノードより大きい場合は交換する
 * 
 * @param heap ヒープ
 * @param index 現在のノードのインデックス
 */
void heapify_down(MaxHeap* heap, int index) {
    int largest = index;
    int left = heap_left_child(index);
    int right = heap_right_child(index);
    
    // 左の子ノードより大きい場合は交換する
    if (left < heap->size && heap->data[left] > heap->data[largest]) {
        largest = left;
    }
    
    // 右の子ノードより大きい場合は交換する
    if (right < heap->size && heap->data[right] > heap->data[largest]) {
        largest = right;
    }
    
    // 親ノードより大きい場合は交換する
    if (largest != index) {
        heap_swap(&heap->data[index], &heap->data[largest]);
        heapify_down(heap, largest);
    }
}

/**
 * ヒープから最大値を取り出す
 * 
 * @param heap ヒープ
 * @return 最大値
 */
int heap_extract_max(MaxHeap* heap) {
    if (heap_is_empty(heap)) {
        printf("Error: Heap is empty\n");
        return -1;
    }
    
    int max_value = heap->data[0];
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;
    
    if (heap->size > 0) {
        heapify_down(heap, 0);
    }
    
    return max_value;
}

/**
 * ヒープの先頭の値を取得する
 * 
 * @param heap ヒープ
 * @return 先頭の値
 */
int heap_peek(MaxHeap* heap) {
    if (heap_is_empty(heap)) {
        printf("Error: Heap is empty\n");
        return -1;
    }
    return heap->data[0];
}

/**
 * ヒープのサイズを取得する
 * 
 * @param heap ヒープ
 * @return ヒープのサイズ
 */
int heap_size(MaxHeap* heap) {
    return heap->size;
}

void heap_print(MaxHeap* heap) {
    if (heap_is_empty(heap)) {
        printf("Heap is empty\n");
        return;
    }
    
    printf("Heap: ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->data[i]);
    }
    printf("\n");
}

void heap_print_tree(MaxHeap* heap) {
    if (heap_is_empty(heap)) {
        printf("Heap is empty\n");
        return;
    }
    
    printf("Heap as tree:\n");
    int level = 0;
    int nodes_in_level = 1;
    int index = 0;
    
    while (index < heap->size) {
        for (int i = 0; i < level; i++) printf("  ");
        
        for (int i = 0; i < nodes_in_level && index < heap->size; i++) {
            printf("%d ", heap->data[index++]);
        }
        printf("\n");
        
        level++;
        nodes_in_level *= 2;
    }
}

