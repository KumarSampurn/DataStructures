#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} node;

node* createNode(int x) {
    node* newNode = malloc(sizeof(node));
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertFrontorBack(node** head, node** tail, int x) {
    node* newNode = createNode(x);

    if (*head == NULL) {
        *head = newNode;
        *tail = newNode;
        (*head)->right = *head;
        (*head)->left = *head;
    } else {
        newNode->right = *head;
        newNode->left = (*tail);
        (*tail)->right = newNode;
        (*head)->left = newNode;
        *head = newNode;
    }
}



void display(node* head) {
    if (head == NULL) {
        printf("Empty\n");
        return;
    }

    node* current = head;
    do {
        printf("%d \t", current->data);
        current = current->right;
    } while (current != head);

    printf("\n");
}

void delFrontorBack(node** head, node** tail) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (*head == (*head)->right) {
        free(*head);
        *head = NULL;
        *tail = NULL;
    } else {
        node* temp = *head;
        (*head)->right->left = *tail;
        (*tail)->right = (*head)->right;
        *head = (*head)->right;
        free(temp);
    }
}


int main() {
    node* head = NULL;
    node* tail = NULL;
    int choice, data;

    while (1) {
        printf("\nDoubly Circular Linked List Operations:\n");
        printf("1. Insert at Front or Back\n");
        printf("2. Display\n");
        printf("3. Delete from Front or Back\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at front or back: ");
                scanf("%d", &data);
                insertFrontorBack(&head, &tail, data);
                break;

            case 2:
                display(head);
                break;

            case 3:
                delFrontorBack(&head, &tail);
                break;

            case 4:
                // Free allocated memory for nodes before exiting
                while (head != NULL) {
                    delFrontorBack(&head, &tail);
                }
                exit(0);

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
