#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* right;

} node;

node* create_node(int x) {
    node* newNode = malloc(sizeof(node));
    newNode->data = x;
    newNode->right =NULL;
    return newNode;
}

node* add_front(node* head, int x){

    node* new_node= create_node(x);

    if(head==NULL){
        head=new_node;
        new_node->right=head;
        return head;
    }


    new_node->right=head;
    head=new_node;

    node* last= head;
    while (last->right!=head)
    {
        last=last->right;
    }
    last->right=new_node;

    return head;

}


void add_back(node** head,int x){
    node* new_node= create_node(x);
    if (*head==NULL)
    {
        head=new_node;
        new_node->right=head;
        return head;
    }
    
    node* last= *head;
    while (last->right!=*head)
    {
        last=last->right;
    }
    last->right=new_node;

    new_node->right=*head;

}


void del_back(node **head)
{

    if(*head==NULL){
        printf("List empty\n");
        return;
    }
    node* temp= *head;
    

    node* prev=NULL;

    while (temp->right!=*head)
    {
        prev=temp;
        temp=temp->right;
    }

    printf("Deleted element is : %d\n",temp->data);
    free(temp);

    if (prev==NULL)
    {
        *head=NULL;  
    }
    else{
        prev->right=*head;
    }

}
