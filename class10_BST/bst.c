#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode {
    int data;
    struct treeNode* left;
    struct treeNode* right;
} node;

// Function to create a new node with the given data
node* createNode(int data) {
    node* newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the binary search tree
node* insertNode(node* root, int data) {
    // Create a new node with the given data
    node* newNode = createNode(data);

    if (root == NULL) {
        return newNode;
    }

    // Traverse the tree to find the appropriate position to insert the new node
    node* cur = root;
    node* parent = NULL;

    while (cur != NULL) {
        parent = cur;
        if (data < cur->data) {
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }

    // Insert the new node into the appropriate location
    if (data < parent->data) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }

    return root;
}

// Function to print the binary search tree using inorder traversal
void inorderTraversal(node* root) {
    if (root == NULL) {
        return;
    }

    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// Function to search for a value in the binary search tree
int search(node* root, int data) {
    if (root == NULL) {
        return 0;
    }

    if (root->data == data) {
        return 1;
    }

    if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

node* inorderSuccesor(node* root) {
    node* current = root;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}

node* delete(node* root, int data) {
    if (root == NULL) {
        return root;
    }

    // if the data is smaller than root node
    if (data < root->data) {
        root->left = delete(root->left, data);
    } else if (data > root->data) {
        root->right = delete(root->right, data);
    } else if (root->data == data) {
        if (root->right == NULL && root->left == NULL) {
            free(root);
            return NULL;
        }

        if (root->right == NULL) {
            node* temp = root->left;
            free(root);
            return temp;
        }

        if (root->left == NULL) {
            node* temp = root->right;
            free(root);
            return temp;
        }

        node* temp = inorderSuccesor(root);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }

    return root;
}

int main() {
    node* root = NULL;
    int choice, data, searchData, deleteData;

    do {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert a value\n");
        printf("2. Inorder Traversal\n");
        printf("3. Search a value\n");
        printf("4. Delete a value\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value to insert: ");
                scanf("%d", &data);
                root = insertNode(root, data);
                break;

            case 2:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;

            case 3:
                printf("Enter a value to search: ");
                scanf("%d", &searchData);
                if (search(root, searchData)) {
                    printf("%d is present in the tree.\n", searchData);
                } else {
                    printf("%d is not present in the tree.\n", searchData);
                }
                break;

            case 4:
                printf("Enter a value to delete: ");
                scanf("%d", &deleteData);
                root = delete(root, deleteData);
                printf("Inorder Traversal after deletion of %d: ", deleteData);
                inorderTraversal(root);
                printf("\n");
                break;

            case 5:
                printf("Exiting program\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);

    // TODO: Free the memory for the BST nodes

    return 0;
}
