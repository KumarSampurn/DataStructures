# Explanation of Functions

In this C program, we define several functions to perform operations on a linked list. Each function serves a specific purpose in manipulating the linked list.

## `node* create_node(int x)`

This function creates a new node with the provided data value `x` and returns a pointer to the newly created node.

- **Parameters:**
  - `x` (int): Data value for the new node.

- **Return:**
  - Returns a pointer to the newly created node.

## `node* insert_front(node* head, int x)`

This function inserts a new node with data value `x` at the front of the linked list.

- **Parameters:**
  - `head` (node*): Pointer to the head of the linked list.
  - `x` (int): Data value for the new node to be inserted.

- **Return:**
  - Returns the updated head of the linked list after insertion.

## `node* insert_back(node* head, int x)`

This function inserts a new node with data value `x` at the back (end) of the linked list.

- **Parameters:**
  - `head` (node*): Pointer to the head of the linked list.
  - `x` (int): Data value for the new node to be inserted.

- **Return:**
  - Returns the updated head of the linked list after insertion.

## `int del_front(node** head)`

This function deletes the node at the front of the linked list.

- **Parameters:**
  - `head` (node**): Pointer to a pointer to the head of the linked list.

- **Return:**
  - Returns the data value of the deleted node.

## `int del_back(node** head)`

This function deletes the node at the back (end) of the linked list.

- **Parameters:**
  - `head` (node**): Pointer to a pointer to the head of the linked list.

- **Return:**
  - Returns the data value of the deleted node.

## `int main()`

The main function drives the program by presenting a menu to the user and invoking the respective functions based on the user's choice. It also manages memory deallocation when exiting the program.

- **Return:**
  - Returns 0 to indicate successful execution of the program.

---

This concludes the explanation of the functions used in the provided C program for performing operations on a linked list.
