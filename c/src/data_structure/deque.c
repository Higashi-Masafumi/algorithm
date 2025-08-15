#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct DequeNode {
    int data;
    struct DequeNode* next; // 次のノードへのポインタ
    struct DequeNode* prev; // 前のノードへのポインタ
} DequeNode;

typedef struct Deque {
    DequeNode* front;
    DequeNode* back;
    int size;
} Deque;

Deque* deque_create() {
    Deque* deque = (Deque*)malloc(sizeof(Deque));
    if (!deque) return NULL;
    
    deque->front = NULL;
    deque->back = NULL;
    deque->size = 0;
    return deque;
}

DequeNode* create_node(int data) {
    DequeNode* node = (DequeNode*)malloc(sizeof(DequeNode));
    if (!node) return NULL;
    
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

bool deque_is_empty(Deque* deque) {
    return deque->size == 0;
}

int deque_size(Deque* deque) {
    return deque->size;
}

void deque_push_front(Deque* deque, int data) {
    DequeNode* node = create_node(data);
    if (!node) return;
    
    if (deque_is_empty(deque)) {
        deque->front = deque->back = node;
    } else {
        node->next = deque->front;
        deque->front->prev = node;
        deque->front = node;
    }
    deque->size++;
}

void deque_push_back(Deque* deque, int data) {
    DequeNode* node = create_node(data);
    if (!node) return;
    
    if (deque_is_empty(deque)) {
        deque->front = deque->back = node;
    } else {
        node->prev = deque->back;
        deque->back->next = node;
        deque->back = node;
    }
    deque->size++;
}

int deque_pop_front(Deque* deque) {
    if (deque_is_empty(deque)) {
        printf("Error: Deque is empty\n");
        return -1;
    }
    
    DequeNode* node = deque->front;
    int data = node->data;
    
    if (deque->size == 1) {
        deque->front = deque->back = NULL;
    } else {
        deque->front = node->next;
        deque->front->prev = NULL;
    }
    
    free(node);
    deque->size--;
    return data;
}

int deque_pop_back(Deque* deque) {
    if (deque_is_empty(deque)) {
        printf("Error: Deque is empty\n");
        return -1;
    }
    
    DequeNode* node = deque->back;
    int data = node->data;
    
    if (deque->size == 1) {
        deque->front = deque->back = NULL;
    } else {
        deque->back = node->prev;
        deque->back->next = NULL;
    }
    
    free(node);
    deque->size--;
    return data;
}

int deque_front(Deque* deque) {
    if (deque_is_empty(deque)) {
        printf("Error: Deque is empty\n");
        return -1;
    }
    return deque->front->data;
}

int deque_back(Deque* deque) {
    if (deque_is_empty(deque)) {
        printf("Error: Deque is empty\n");
        return -1;
    }
    return deque->back->data;
}

void deque_destroy(Deque* deque) {
    while (!deque_is_empty(deque)) {
        deque_pop_front(deque);
    }
    free(deque);
}

void deque_print(Deque* deque) {
    if (deque_is_empty(deque)) {
        printf("Deque is empty\n");
        return;
    }
    
    printf("Deque (front to back): ");
    DequeNode* current = deque->front;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Deque* deque = deque_create();
    
    deque_push_back(deque, 1);
    deque_push_back(deque, 2);
    deque_push_front(deque, 0);
    deque_push_front(deque, -1);
    
    printf("Size: %d\n", deque_size(deque));
    deque_print(deque);
    
    printf("Front: %d\n", deque_front(deque));
    printf("Back: %d\n", deque_back(deque));
    
    printf("Pop front: %d\n", deque_pop_front(deque));
    printf("Pop back: %d\n", deque_pop_back(deque));
    
    deque_print(deque);
    
    deque_destroy(deque);
    return 0;
}