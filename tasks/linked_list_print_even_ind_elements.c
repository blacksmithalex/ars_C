#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void append(Node **head, int value) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (!new_node) {
        perror("Error allocating memory");
        exit(1);
    }
    new_node->data = value;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        Node *temp = *head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    printf("ok\n");
}

void print_even_index(Node **head) {
    if (*head == NULL) {
        printf("NO EVEN INDEX\n");
        return;
    }
    Node *current = *head;
    while (current) {
        printf("%d -> ", current->data);
        if (current->next)
            current = current->next->next;
        else
            break;
    }
}

void free_list(Node **head) {
    Node *temp;
    while (*head) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main() {
    Node *head = NULL;
    char command[10];
    int value;
    scanf("%d", &value);
    while (value != 0) {
        append(&head, value);
        scanf("%d", &value);
    }
    print_even_index(&head);
    free_list(&head);
    return 0;
}
