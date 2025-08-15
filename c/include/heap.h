#pragma once
#include <stdbool.h>

typedef struct MaxHeap {
    int* data;
    int size;
    int capacity;
} MaxHeap;

MaxHeap* heap_create(int capacity);
void heap_destroy(MaxHeap* heap);
bool heap_is_empty(MaxHeap* heap);
bool heap_is_full(MaxHeap* heap);
bool heap_insert(MaxHeap* heap, int value);
int heap_extract_max(MaxHeap* heap);
int heap_peek(MaxHeap* heap);
int heap_size(MaxHeap* heap);
void heap_print(MaxHeap* heap);