#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
} Node;

Node *create_node(int value) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (!new_node) {
        perror("Error allocating memory");
        exit(1);
    }
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Node *add_node(Node *root, int value) {
    if (!root) {
        return create_node(value);
    }
    if (value < root->value) {
        root->left = add_node(root->left, value); 
    } else if (value > root->value) {
        root->right = add_node(root->right, value); 
    }
    return root; 
}

int tree_height(Node *root) {
    if (!root) {
        return 0; 
    }
    int left_height = tree_height(root->left);  
    int right_height = tree_height(root->right); 
    return 1 + (left_height > right_height ? left_height : right_height); 
}

void free_tree(Node *root) {
    if (!root) {
        return;
    }
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

int main() {
    Node *root = NULL;
    int value;

    while (1) {
        scanf("%d", &value);
        if (value == 0) {
            break;
        }
        root = add_node(root, value); 
    }

    int height = tree_height(root);
    printf("%d\n", height);

    free_tree(root);
    return 0;
}
