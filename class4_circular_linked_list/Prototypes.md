# Doubly Circular Linked List Operations

This C program implements various operations on a doubly circular linked list.

## `node* createNode(int x)`

This function creates a new node with the given data value `x`.

- **Parameters:**
  - `x` (int): Data value for the new node.

- **Return:**
  - Returns a pointer to the newly created node.

## `void insertFrontorBack(node** head, node** tail, int x)`

This function inserts a new node with data value `x` at the front or back of a doubly circular linked list.

- **Parameters:**
  - `head` (node**): Pointer to a pointer to the head of the linked list.
  - `tail` (node**): Pointer to a pointer to the tail of the linked list.
  - `x` (int): Data value for the new node to be inserted.

- **Return:**
  - No return value.

## `void display(node* head)`

This function displays the elements of the doubly circular linked list starting from the head and traversing in a circular manner.

- **Parameters:**
  - `head` (node*): Pointer to the head of the linked list.

- **Return:**
  - No return value.

## `void delFrontorBack(node** head, node** tail)`

This function deletes the node at the front or back of the doubly circular linked list. Deleting from the front is the same as deleting from the back in a doubly circular linked list.

- **Parameters:**
  - `head` (node**): Pointer to a pointer to the head of the linked list.
  - `tail` (node**): Pointer to a pointer to the tail of the linked list.

- **Return:**
  - No return value.

## `int main()`

The main function provides a menu for interacting with the doubly circular linked list, allowing users to perform insertions at the front or back, display the list, delete from the front or back, and exit the program. It calls the respective functions based on the user's choice.

---

This concludes the description of the functions in the provided C program for a doubly circular linked list.
