# Explanation of the C Code for Linked List Operations

In this C program, we implement a linked list data structure and provide various functions to perform operations on it. Below is an explanation of each function and its role in the program.

## `node* create_node(int x)`

```C
node* create_node(int x){

    node* new_node=(node*)malloc(sizeof(node));
  
    new_node->data=x;
    new_node->next=NULL;

    return new_node;
    
}
```

* This code segments creates a new node with data value `x` and returns a pointer to it.

* As the dynamic memory takes place in heap, and we know heap memory is limited, so there is a possibility that the memory allocation fails.

* Its a good practice to check if the memory allocation was successful or not. If the memory allocation fails, then the function returns `NULL`.

  * ```c
        node* create_node(int x){

            node* new_node=(node*)malloc(sizeof(node));
            
            if(new_node==NULL){
                printf("Memory allocation failed\n");
                return NULL;
            }
            
            new_node->data=x;
            new_node->next=NULL;

            return new_node;
            
        }
    ```

* These doesnt happen in nowadays computers since we have a lot of memory.

## `node* insert_front(node* head, int x)`

```C
node* insert_front(node* head,int x){

    node* new_node=create_node(x);
    new_node->next=head;


    head=new_node;
    return head;
   
}
```

* Creating a New Node
* Updating the Next Pointer of the New Node
  * Think about what will happen if
    * `head` is `NULL`
    * `head` is not `NULL`
* Updating the Head Pointer
* Returning the Updated Head Pointer

## `node* insert_back(node* head, int x)`

```C
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
```

* Creating a New Node
* Checking if the Linked List is Empty
* Traversing to the End of the List
* Updating the Next Pointer of the Last Node
* Returning the Original Head Pointer

## `int del_front(node** head)`

```C
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
```

> **Note:**  **head points to the head pointer of the linked list.**

Refer to DMA for more details.

* Checking if the Linked List is Empty
* Storing the Address of the First Node
* Updating the Head Pointer
* Storing the Data Value of the First Node
* Freeing the Memory Occupied by the First Node
* Returning the Data Value of the First Node

## `int del_back(node** head)`

```C
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
```

> **Note:**  **head points to the head pointer of the linked list.**  

Refer to DMA for more details.

* Checking if the Linked List is Empty
* Traversing to the End of the List
  * Here the `prev` pointer is used to keep track of the previous node.
* Storing the Data Value of the Last Node
* Freeing the Memory Occupied by the Last Node
* Updating the Next Pointer of the Second Last Node
* Returning the Data Value of the Last Node
