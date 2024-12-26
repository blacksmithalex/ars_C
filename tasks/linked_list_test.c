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

void prepend(Node **head, int value) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (!new_node) {
        perror("Error allocating memory");
        exit(1);
    }
    new_node->data = value;
    new_node->next = *head;
    *head = new_node;
    printf("ok\n");
}

void delete(Node **head, int value) {
    if (*head == NULL) {
        printf("error\n");
        return;
    }

    if ((*head)->data == value) {
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        printf("ok\n");
        return;
    }

    Node *current = *head;
    while (current->next && current->next->data != value) {
        current = current->next;
    }

    if (current->next == NULL) {
        printf("error\n");
    } else {
        Node *temp = current->next;
        current->next = temp->next;
        free(temp);
        printf("ok\n");
    }
}

void display(Node *head) {
    if (head == NULL) {
        printf("NULL\n");
        return;
    }

    Node *temp = head;
    while (temp) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
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

    while (scanf("%s", command) != EOF) {
        if (strcmp(command, "append") == 0) {
            scanf("%d", &value);
            append(&head, value);
        } else if (strcmp(command, "prepend") == 0) {
            scanf("%d", &value);
            prepend(&head, value);
        } else if (strcmp(command, "delete") == 0) {
            scanf("%d", &value);
            delete(&head, value);
        } else if (strcmp(command, "display") == 0) {
            display(head);
        } else if (strcmp(command, "exit") == 0) {
            free_list(&head);
            printf("bye\n");
            break;
        } else {
            printf("Unknown command\n");
        }
    }

    return 0;
}
