#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int data;
    struct stack* next;
} stack;

stack* create_stack(int x) {
    stack* new_stack = (stack*)malloc(sizeof(stack));
    new_stack->data = x;
    new_stack->next = NULL;
    return new_stack;
}

stack* insert_back(stack* head, int x) {
    stack* new_stack = create_stack(x);

    if (!head)
        return new_stack;

    stack* cur = head;

    while (cur->next != NULL) {
        cur = cur->next;
    }

    cur->next = new_stack;
    return head;
}

int del_back(stack** head) {
    if (!*head) {
        printf("Empty List");
        return -999999;
    }

    stack* cur = *head;
    stack* prev = NULL;

    while (cur->next != NULL) {
        prev = cur;
        cur = cur->next;
    }

    int x = cur->data;
    free(cur);

    if (prev != NULL) {
        prev->next = NULL;
    }
    else{
        *head=NULL;
    }

    return x;
}

int main() {
    stack* head = NULL; // Initialize an empty stack

    int choice, value;
    do {
        printf("Stack Operations:\n");
        printf("1. Push (insert back)\n");
        printf("2. Pop (delete back)\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                head = insert_back(head, value);
                break;
            case 2:
                value = del_back(&head);
                if (value != -999999) {
                    printf("Popped value: %d\n", value);
                }
                break;
            case 3:
                printf("Exiting...\n");
                // Free remaining memory before exiting
                while (head != NULL) {
                    del_back(&head);
                }
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 3);

    return 0;
}
