#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *data;      
    int size;       
    int capacity;  
} Stack;

void stack_init(Stack *stack) {
    stack->data = malloc(4 * sizeof(int));
    stack->size = 0;
    stack->capacity = 4;
}

void stack_free(Stack *stack) {
    free(stack->data);
}

void stack_resize(Stack *stack) {
    stack->capacity *= 2;
    int *new_data = realloc(stack->data, stack->capacity * sizeof(int));
    stack->data = new_data;
}

void stack_push(Stack *stack, int value) {
    if (stack->size == stack->capacity) {
        stack_resize(stack);
    }
    stack->data[stack->size++] = value;
    printf("ok\n");
}

void stack_pop(Stack *stack) {
    if (stack->size == 0) {
        printf("error\n");
    } else {
        printf("%d\n", stack->data[--stack->size]);
    }
}

void stack_back(Stack *stack) {
    if (stack->size == 0) {
        printf("error\n");
    } else {
        printf("%d\n", stack->data[stack->size - 1]);
    }
}

void stack_size(Stack *stack) {
    printf("%d\n", stack->size);
}

void stack_clear(Stack *stack) {
    stack->size = 0;
    printf("ok\n");
}

int main() {
    Stack stack;
    stack_init(&stack);

    char command[10];
    int value;

    while (1) {
        scanf("%s", command);

        if (strcmp(command, "push") == 0) {
            scanf("%d", &value);
            stack_push(&stack, value);
        } else if (strcmp(command, "pop") == 0) {
            stack_pop(&stack);
        } else if (strcmp(command, "back") == 0) {
            stack_back(&stack);
        } else if (strcmp(command, "size") == 0) {
            stack_size(&stack);
        } else if (strcmp(command, "clear") == 0) {
            stack_clear(&stack);
        } else if (strcmp(command, "exit") == 0) {
            printf("bye\n");
            break;
        } 
    }

    stack_free(&stack);
    return 0;
}
