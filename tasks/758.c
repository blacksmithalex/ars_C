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

int tree_count_nodes(Node *root) {
    if (!root) {
        return 0; 
    }
    int left_count = tree_count_nodes(root->left);  
    int right_count = tree_count_nodes(root->right); 
    return 1 + left_count + right_count;
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

    int count = tree_count_nodes(root);
    printf("%d\n", count);

    free_tree(root);
    return 0;
}
