#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node* left;
    struct node* right;
} node;

void preorder(node* root) {
    if (root == NULL) {
        return;
    }

    printf("%d\t", root->val);
    preorder(root->left);
    preorder(root->right);
}

void inorder(node* root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    printf("%d\t", root->val);
    inorder(root->right);
}

void postorder(node* root) {
    if (root == NULL) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%d\t", root->val);
}

node* createnode(int val) {
    node* new_node = malloc(sizeof(node));
    new_node->val = val;
    new_node->left = new_node->right = NULL;
    return new_node;
}

node* insert(node* root, int val) {
    if (root == NULL)
        return createnode(val);

    if (val >= root->val)
        root->right = insert(root->right, val);
    else
        root->left = insert(root->left, val);

    return root;
}

int main() {
    node* root = NULL;
    int choice;

    do {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert a value\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int val;
                printf("Enter a value to insert: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;
            }
            case 2:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 3:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 4:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 5:
                printf("Exiting program\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);

    // Free allocated memory for nodes before exiting
    // TODO: Add a function to free the BST nodes

    return 0;
}
