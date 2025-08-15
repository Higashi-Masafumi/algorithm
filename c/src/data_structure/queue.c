#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000

typedef struct {
    int data[MAX_SIZE];
    int head;
    int tail;
    int size;
} Queue;

void init_queue(Queue *queue) {
    queue->head = 0;
    queue->tail = -1;
    queue->size = 0;
}

bool is_empty(Queue *queue) {
    return queue->size == 0;
}

bool is_full(Queue *queue) {
    return queue->size == MAX_SIZE;
}

void enqueue(Queue *queue, int value) {
    if (is_full(queue)) {
        printf("Queue is full\n");
        return;
    }
    queue->tail = (queue->tail + 1) % MAX_SIZE; // 循環するようにする
    queue->data[queue->tail] = value;
    queue->size++;
}

int dequeue(Queue *queue) {
    if (is_empty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    int value = queue->data[queue->head];
    queue->head = (queue->head + 1) % MAX_SIZE; // 循環するようにする
    queue->size--;
    return value;
}

int front(Queue *queue) {
    if (is_empty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->data[queue->head];
}

void print_queue(Queue *queue) {
    if (is_empty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    int index = queue->head;
    for (int i = 0; i < queue->size; i++) {
        printf("%d ", queue->data[index]);
        index = (index + 1) % MAX_SIZE; // 循環するようにする
    }
    printf("\n");
}

int main() {
    Queue queue;
    init_queue(&queue);
    
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    
    print_queue(&queue);
    
    printf("dequeue: %d\n", dequeue(&queue));
    printf("front: %d\n", front(&queue));
    
    print_queue(&queue);
    
    return 0;
}