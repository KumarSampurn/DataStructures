#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;


node* create_node(int x){

    node* new_node=(node*)malloc(sizeof(node));
  
    new_node->data=x;
    new_node->next=NULL;

    return new_node;
    
}


node* insert_front(node* head,int x){

    node* new_node=create_node(x);
    new_node->next=head;


    head=new_node;
    return head;
   
}


node* insert_back(node* head,int x){

    node* new_node=create_node(x);

    if (!head)
        return new_node;
    
    node* cur=head;

    while (cur->next!=NULL)
    {
        cur=cur->next;
    }

    cur->next=new_node;
    return head;

}


int del_front(node** head){

    if (!*head){
        printf("Empty List");
        return -999999 ;
    }
        

    node* first= *head;

    *head=(*head)->next;

    int x= first->data;

    free (first);   

    return x;
    
    
   
}


int del_back(node** head){

    if (!*head){
        printf("Empty List");
        return -999999;
    }


    node* cur=*head;
    node* prev=NULL;

    while (cur->next!=NULL)
    {
        prev=cur;
        cur=cur->next;
    }

    int x=cur->data;
    free(cur);

    if (prev!=NULL)
    {
        prev->next=NULL;
    }

    return x;
}


int main() {
    node* head = NULL;

    int choice, x;
    
    while (1) {
        printf("\nLinked List Operations:\n");
        printf("1. Insert at the front\n");
        printf("2. Insert at the back\n");
        printf("3. Delete from the front\n");
        printf("4. Delete from the back\n");
        printf("5. Display the linked list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert at the front: ");
                scanf("%d", &x);
                head = insert_front(head, x);
                break;

            case 2:
                printf("Enter the value to insert at the back: ");
                scanf("%d", &x);
                head = insert_back(head, x);
                break;

            case 3:
                x = del_front(&head);
                printf("Deleted from the front: %d\n", x);
                break;

            case 4:
                x = del_back(&head);
                printf("Deleted from the back: %d\n", x);
                break;

            case 5:
                printf("Linked list: ");
                node* current = head;
                while (current != NULL) {
                    printf("%d ", current->data);
                    current = current->next;
                }
                printf("\n");
                break;

            case 6:
                // Free memory by deleting the remaining nodes
                while (head != NULL) {
                    del_front(&head);
                }
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}




// Search element in linked list
// delete search element

// delete nth element from linked list
// delete alternate element from linked list 


// insert at pos
// insert after key

// find middle of an linked list
