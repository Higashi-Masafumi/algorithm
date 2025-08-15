#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "../../include/utils.h"

/**
 * ノードを作成する
 * 
 * @param key ノードのキー
 * @param priority ノードの優先度
 * @return 作成されたノード
 */
typedef struct TreapNode {
    int key;
    int priority;
    struct TreapNode* left;
    struct TreapNode* right;
} TreapNode;

TreapNode* create_node(int key) {
    TreapNode* node = (TreapNode*)malloc(sizeof(TreapNode));
    if (!node) return NULL;
    
    node->key = key;
    node->priority = rand();
    node->left = NULL;
    node->right = NULL;
    return node;
}

TreapNode* rotate_right(TreapNode* root) {
    TreapNode* left_child = root->left;
    root->left = left_child->right;
    left_child->right = root;
    return left_child;
}

TreapNode* rotate_left(TreapNode* root) {
    TreapNode* right_child = root->right;
    root->right = right_child->left;
    right_child->left = root;
    return right_child;
}

TreapNode* insert(TreapNode* root, int key) {
    if (root == NULL) {
        return create_node(key);
    }
    
    if (key < root->key) {
        root->left = insert(root->left, key);
        if (root->left->priority > root->priority) {
            root = rotate_right(root);
        }
    } else if (key > root->key) {
        root->right = insert(root->right, key);
        if (root->right->priority > root->priority) {
            root = rotate_left(root);
        }
    }
    
    return root;
}

TreapNode* delete_node(TreapNode* root, int key) {
    if (root == NULL) {
        return root;
    }
    
    if (key < root->key) {
        root->left = delete_node(root->left, key);
    } else if (key > root->key) {
        root->right = delete_node(root->right, key);
    } else {
        if (root->left == NULL) {
            TreapNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            TreapNode* temp = root->left;
            free(root);
            return temp;
        } else {
            if (root->left->priority > root->right->priority) {
                root = rotate_right(root);
                root->right = delete_node(root->right, key);
            } else {
                root = rotate_left(root);
                root->left = delete_node(root->left, key);
            }
        }
    }
    
    return root;
}

bool search(TreapNode* root, int key) {
    if (root == NULL) {
        return false;
    }
    
    if (key == root->key) {
        return true;
    }
    
    if (key < root->key) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

void inorder_traversal(TreapNode* root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("(%d,%d) ", root->key, root->priority);
        inorder_traversal(root->right);
    }
}

void preorder_traversal(TreapNode* root) {
    if (root != NULL) {
        printf("(%d,%d) ", root->key, root->priority);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

void free_treap(TreapNode* root) {
    if (root != NULL) {
        free_treap(root->left);
        free_treap(root->right);
        free(root);
    }
}

int treap_height(TreapNode* root) {
    if (root == NULL) {
        return 0;
    }
    
    int left_height = treap_height(root->left);
    int right_height = treap_height(root->right);
    
    return 1 + (left_height > right_height ? left_height : right_height);
}

int treap_size(TreapNode* root) {
    if (root == NULL) {
        return 0;
    }
    
    return 1 + treap_size(root->left) + treap_size(root->right);
}

void print_tree_structure(TreapNode* root, int level) {
    if (root != NULL) {
        print_tree_structure(root->right, level + 1);
        
        for (int i = 0; i < level; i++) {
            printf("    ");
        }
        printf("(%d,%d)\n", root->key, root->priority);
        
        print_tree_structure(root->left, level + 1);
    }
}

int main() {
    srand(time(NULL));
    TreapNode* root = NULL;
    
    int values[10];
    random_sequence(values, 10);
    int n = sizeof(values) / sizeof(values[0]);
    
    printf("Inserting values into Treap:\n");
    for (int i = 0; i < n; i++) {
        printf("Inserting %d...\n", values[i]);
        root = insert(root, values[i]);
    }
    
    printf("\nTreap structure (rotated 90 degrees):\n");
    print_tree_structure(root, 0);
    
    printf("\nTreap height: %d\n", treap_height(root));
    printf("Treap size: %d\n", treap_size(root));
    
    printf("\nInorder traversal (keys in BST order): ");
    inorder_traversal(root);
    printf("\n");
    
    printf("Preorder traversal (heap order by priority): ");
    preorder_traversal(root);
    printf("\n");
    
    int search_key = 40;
    printf("\nSearching for %d: %s\n", search_key, search(root, search_key) ? "Found" : "Not found");
    
    search_key = 99;
    printf("Searching for %d: %s\n", search_key, search(root, search_key) ? "Found" : "Not found");
    
    printf("\nDeleting 30...\n");
    root = delete_node(root, 30);
    printf("Inorder after deletion: ");
    inorder_traversal(root);
    printf("\n");
    
    printf("\nDeleting 50...\n");
    root = delete_node(root, 50);
    printf("Inorder after deletion: ");
    inorder_traversal(root);
    printf("\n");
    
    free_treap(root);
    return 0;
}