#include <stdio.h>
#include <stdlib.h>

// Define the structure for the binary tree node
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
    if(root==NULL){
        return 0;
    }
    if (root->data == data) {
        return 1;
    }
     

    if (data < root->data) {
        search(root->left, data);
    } else {
        search(root->right, data);
    }

}



 node * inorderSuccesor( node* root) {
    node* current = root;
 
    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;
 
    return current;
}



node* delete(node* root , int data){

    if (root== NULL)
    {
        return root;
    }

    // if the data is smaller than root node
    if (data < root->data)
    {
        root->left= delete(root->left, data);
    }

    else if (data > root->data)
    {
        root->right= delete(root->right, data);
    }

    // root -> data == data

    else if(root -> data == data){

        if(root->right == NULL && root ->left ==NULL){
            free(root);
            return NULL;
        }

         if (root->right==NULL)
        {
            node* temp= root->left;
            free(root);
            return ( temp);
        }

        if (root->left==NULL)
        {
            node* temp= root->right;
            free(root);
            return ( temp);
        }
        
        node* temp= inorderSuccesor(root);

        root->data=temp->data;

        root->right=delete(root->right,root->data);
        

    }


    // root-> data != data   
        return root;


}



int main() {
    node* root = NULL;

    // Insert nodes into the binary search tree
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 70);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 60);

    // Print the binary search tree using inorder traversal
    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    // Search for a value in the binary search tree
    // search(root, 30);
    printf("%d\n", search(root, 60));

    // Cleanup: free the memory used by the tree nodes (not shown in this code)

    delete(root,60);
    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");


    return 0;
}



