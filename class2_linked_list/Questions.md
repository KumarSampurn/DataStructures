# Questions for Linked List

* Search for a value in a linked list
* Insert at Specific Position in a linked list
* Delete from a specific position in a linked list
* Reverse a linked list

* Detect a cycle in a linked list
* Find the length of a linked list
* Find the middle element of a linked list

Try to solve these questions on your own. If you get stuck, you can refer to the answers below.

# Answers

## Search for a value in a linked list

```c
int search(node* head, int key) {

    node* cur = head;
    int i = 0;

    while (cur != NULL) {
        if (cur->data == key) {
            return i;
        }
        cur = cur->next;
        i++;
    }

    return -1; 
}

```

## Insert at Specific Position in a linked list

```c
node* insert_at_pos(node* head, int x, int pos) {

    if (pos == 0) {
        insert_front(head, x);
    }

    node* new_node = create_node(x);

    node* cur = head;
    node* prev = NULL;
    int i = 0;

    while (cur != NULL && i < pos) {
        prev = cur;
        cur = cur->next;
        i++;
    }

    prev->next = new_node;
    new_node->next = cur;

    return head;
}

```

## Delete from a specific position in a linked list

```c

node* delete_at_pos(node* head, int pos) {

    if (pos == 0) {
        delete_front(head);
    }

    node* cur = head;
    node* prev = NULL;
    int i = 0;

    while (cur != NULL && i < pos) {
        prev = cur;
        cur = cur->next;
        i++;
    }

    prev->next = cur->next;
    free(cur);

    return head;
}

```

## Reverse a linked list

This is a tricky one. I recommend you watch this video: <https://www.youtube.com/watch?v=O0By4Zq0OFc>.

Its one of the best explanations out there.

```c
node* reverse(node* head) {

    node* cur = head;
    node* prev = NULL;
    node* next = NULL;

    while (cur != NULL) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    return prev;
}

```

## Detect a cycle in a linked list

Refer to floyd's cycle detection algorithm for this one.

The rabbit and tortoise analogy is so cool!

```c
int floyd_detect_cycle(node* head) {

    node* tortoise = head;
    node* rabbit = head;

    while (rabbit != NULL && rabbit->next != NULL) {
        tortoise = tortoise->next;
        rabbit = rabbit->next->next;

        if (tortoise == rabbit) {
            return 1;
        }
    }

    return 0;
}

```

## Find the middle element of a linked list

Well the logic is simple. We use the same rabbit and tortoise analogy as above.

Now try to answer this question by yourself.

> If the rabbit is twice as fast as the tortoise, where will the tortoise be when the rabbit reaches the end of the list?
