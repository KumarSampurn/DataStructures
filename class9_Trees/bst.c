#include <stdio.h>
#include<stdlib.h>

typedef struct node
{
    int val;
    struct node* left;
    struct node* right;

}node;


void preorder(node* root){

    if (root==NULL)
    {
        return ;
    }

    printf("%d\t", root->val);
    preorder(root->left);
    preorder(root->right);

}
void inorder(node* root){

    if (root==NULL)
    {
        return ;
    }

    inorder(root->left);
    printf("%d\t", root->val);
    inorder(root->right);

}
void postorder(node* root){

    if (root==NULL)
    {
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%d\t", root->val);

}


node* createnode(int val){

    node* new_node=malloc(sizeof(node));
    new_node->val=val;
    new_node->left=new_node->right=NULL;
    return new_node;
}


void insert(node* root, int val){
    

    if(root==NULL)
        return createnode(val);

    
    if (val >=root->val)
    {
        root->right=insert(root->right,val);       
    }
    else{
        root->left=insert(root->left,val);
    }

    return root;
    

}

int main() {
    node* root = NULL;

    // Insert some values into the BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preorder(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}
