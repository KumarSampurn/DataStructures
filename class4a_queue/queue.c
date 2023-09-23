#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
    int data;
    struct queue* next;
} queue;

queue* create_queue(int x) {
    queue* new_queue = (queue*)malloc(sizeof(queue));
    new_queue->data = x;
    new_queue->next = NULL;
    return new_queue;
}

queue* insert_front(queue* head, int x) {
    queue* new_queue = create_queue(x);
    new_queue->next = head;
    head = new_queue;
    return head;
}

int del_back(queue** head) {
    if (!*head) {
        printf("Empty List");
        return -99;
    }
    
    queue* cur = *head;
    queue* prev = NULL;

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
    queue* head = NULL; // Initialize an empty queue

    int choice, value;
    do {
        printf("queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                head = insert_front(head, value);
                break;
            case 2:
                value = del_back(&head);
                if (value != -99) {
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
