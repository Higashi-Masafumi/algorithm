#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../include/utils.h"

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

/**
 * ノードを作成する
 * 
 * @param data ノードのデータ
 * @return 作成されたノード
 */
TreeNode* create_node(int data) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    if (!node) return NULL;
    
    node->data = data;  // データを設定
    node->left = NULL;  // 左の子を設定
    node->right = NULL; // 右の子を設定
    return node;
}

/**
 * ノードを挿入する
 * 
 * @param root ルートノード
 * @param data 挿入するデータ
 * @return 挿入されたノード
 */
TreeNode* insert(TreeNode* root, int data) {
    if (root == NULL) {
        return create_node(data);
    }
    
    // データがルートノードより小さい場合は左に挿入
    if (data < root->data) {
        root->left = insert(root->left, data);
    } 
    // データがルートノードより大きい場合は右に挿入
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    
    return root;
}

/**
 * ノードを検索する
 * 
 * @param root ルートノード
 * @param data 検索するデータ
 * @return 検索結果
 */
bool search(TreeNode* root, int data) {
    if (root == NULL) {
        return false;
    }
    
    if (data == root->data) {
        return true;
    }
    
    // データがルートノードより小さい場合は左に検索
    if (data < root->data) {
        return search(root->left, data);
    } 
    // データがルートノードより大きい場合は右に検索
    else {
        return search(root->right, data);
    }
}

/**
 * 最小値を探す
 * 
 * @param root ルートノード
 * @return 最小値
 */
TreeNode* find_min(TreeNode* root) {
    while (root && root->left) {
        root = root->left;
    }
    return root;
}

/**
 * ノードを削除する
 * 
 * @param root ルートノード
 * @param data 削除するデータ
 * @return 削除後のルートノード
 */
TreeNode* delete_node(TreeNode* root, int data) {
    if (root == NULL) {
        return root;
    }
    
    // データがルートノードより小さい場合は左に削除
    if (data < root->data) {
        root->left = delete_node(root->left, data);
    } 
    // データがルートノードより大きい場合は右に削除
    else if (data > root->data) {
        root->right = delete_node(root->right, data);
    } 
    // データがルートノードと一致する場合は削除
    else {
        // 左の子がない場合は右の子を返す
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        // 右の子がない場合は左の子を返す
        } else if (root->right == NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        
        TreeNode* temp = find_min(root->right);
        root->data = temp->data;
        root->right = delete_node(root->right, temp->data);
    }
    
    return root;
}

void inorder_traversal(TreeNode* root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

void preorder_traversal(TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

void postorder_traversal(TreeNode* root) {
    if (root != NULL) {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf("%d ", root->data);
    }
}

void free_tree(TreeNode* root) {
    if (root != NULL) {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}

int tree_height(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    
    int left_height = tree_height(root->left);
    int right_height = tree_height(root->right);
    
    return 1 + (left_height > right_height ? left_height : right_height);
}

int tree_size(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    
    return 1 + tree_size(root->left) + tree_size(root->right);
}

int main() {
    TreeNode* root = NULL;

    int values[10];
    random_sequence(values, 10);
    int n = sizeof(values) / sizeof(values[0]);
    
    printf("Inserting values: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", values[i]);
        root = insert(root, values[i]);
    }
    printf("\n\n");
    
    printf("Tree height: %d\n", tree_height(root));
    printf("Tree size: %d\n\n", tree_size(root));
    
    printf("Inorder traversal (sorted): ");
    inorder_traversal(root);
    printf("\n");
    
    printf("Preorder traversal: ");
    preorder_traversal(root);
    printf("\n");
    
    printf("Postorder traversal: ");
    postorder_traversal(root);
    printf("\n\n");
    
    int search_value = 40;
    printf("Searching for %d: %s\n", search_value, search(root, search_value) ? "Found" : "Not found");
    
    search_value = 99;
    printf("Searching for %d: %s\n\n", search_value, search(root, search_value) ? "Found" : "Not found");
    
    printf("Deleting 20...\n");
    root = delete_node(root, 20);
    printf("Inorder after deletion: ");
    inorder_traversal(root);
    printf("\n");
    
    printf("Deleting 30...\n");
    root = delete_node(root, 30);
    printf("Inorder after deletion: ");
    inorder_traversal(root);
    printf("\n");
    
    free_tree(root);
    return 0;
}