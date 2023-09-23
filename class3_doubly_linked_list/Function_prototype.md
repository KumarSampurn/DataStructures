# Explanation of Functions

In this C program, we define several functions to perform operations on a Doubly linked list. Each function serves a specific purpose in manipulating the linked list.


The groundwork was done in the previous class, where we defined the structure of a node in the linked list. In this class, we will define the functions to perform operations on the linked list.



## `node* createNode(int x)`

This function creates a new node with the provided data value `x` and returns a pointer to the newly created node.

- **Parameters:**
  - `x` (int): Data value for the new node.

- **Return:**
  - Returns a pointer to the newly created node.

## `void insertFront(node** head, node** tail, int x)`

This function inserts a new node with data value `x` at the front of the linked list.

- **Parameters:**
  - `head` (node**): Pointer to a pointer to the head of the linked list.
  - `tail` (node**): Pointer to a pointer to the tail of the linked list.
  - `x` (int): Data value for the new node to be inserted.

- **Return:**
  - No return value.

## `node* insertBack(node* head, node* tail, int x)`

This function inserts a new node with data value `x` at the back (end) of the linked list.

- **Parameters:**
  - `head` (node*): Pointer to the head of the linked list.
  - `tail` (node*): Pointer to the tail of the linked list.
  - `x` (int): Data value for the new node to be inserted.

- **Return:**
  - Returns the updated head of the linked list after insertion.


- You can directly use the tail pointer for this one but that wouldve been too easy.

## `void display(node* head)`

This function displays the elements of the doubly linked list starting from the head. It traverses the list and prints each element's data.

- **Parameters:**
  - `head` (node*): Pointer to the head of the linked list.

- **Return:**
  - No return value.

## `node* delFront(node* head, node* tail)`

This function deletes the node at the front of the linked list.

- **Parameters:**
  - `head` (node*): Pointer to the head of the linked list.
  - `tail` (node*): Pointer to the tail of the linked list.

- **Return:**
  - Returns the updated head of the linked list after deletion.

## `node* insertPosition(node* head, node* tail, int x, int pos)`

This function inserts a new node with data value `x` at a specified position in the doubly linked list.

- **Parameters:**
  - `head` (node*): Pointer to the head of the linked list.
  - `tail` (node*): Pointer to the tail of the linked list.
  - `x` (int): Data value for the new node to be inserted.
  - `pos` (int): Position at which the new node should be inserted.

- **Return:**
  - Returns the updated head of the linked list after insertion.

## `int main()`

The main function drives the program by presenting a menu to the user and invoking the respective functions based on the user's choice. It also manages memory deallocation when exiting the program.

- **Return:**
  - Returns 0 to indicate successful execution of the program.

---

This concludes the explanation of the functions used in the provided C program for performing operations on a linked list.
