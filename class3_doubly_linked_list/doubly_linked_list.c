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
    newNode->left = newNode->right = NULL;
    return newNode;
}

void insertFront(node** head, node** tail, int x) {
    node* newNode = createNode(x);

    if (!*head) {
        *head = newNode;
        *tail = newNode;
        return;
    }

    newNode->right = *head;
    (*head)->left = newNode;
    *head = newNode;
}

node* insertBack(node* head, node* tail, int x) {
    node* newNode = createNode(x);

    if (!head) {
        head = newNode;
        tail = newNode;
        return head;
    }

    node* cur = head;
    while (cur->right != NULL) {
        cur = cur->right;
    }
    cur->right = newNode;
    newNode->left = cur;

    tail = newNode;

    return head;
}

void display(node* head) {
    if (!head) {
        printf("Empty\n");
        return;
    }

    while (head != NULL) {
        printf("%d \t", head->data);
        head = head->right;
    }
    printf("\n");
}

node* delFront(node* head, node* tail) {
    node* first = head;

    if (first == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    if (head == tail) {
        free(head);
        head = tail = NULL;
        return NULL;
    }

    head = head->right;
    head->left = NULL;
    free(first);

    return head;
}

node* insertPosition(node* head, node* tail, int x, int pos) {
    if (pos <= 0) {
        printf("Invalid position\n");
        return head;
    }

    if (pos == 1) {
        insertFront(&head, &tail, x);
        return head;
    }

    node* newNode = createNode(x);

    int count = 1;
    node* i = head;
    while (i->right != NULL) {
        if (count == pos) {
            break;
        }

        count++;
        i = i->right;
    }

    if (i->right == NULL) {
        return insertBack(head, tail, x);
    }

    newNode->right = i;
    newNode->left = i->left;

    i->left->right = newNode;
    i->left = newNode;

    return head;
}

int main() {
    node* head = NULL;
    node* tail = NULL;
    int choice, data, pos;

    while (1) {
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Back\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Front\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at front: ");
                scanf("%d", &data);
                insertFront(&head, &tail, data);
                break;

            case 2:
                printf("Enter data to insert at back: ");
                scanf("%d", &data);
                head = insertBack(head, tail, data);
                break;

            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert at: ");
                scanf("%d", &pos);
                head = insertPosition(head, tail, data, pos);
                break;

            case 4:
                head = delFront(head, tail);
                break;

            case 5:
                display(head);
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
