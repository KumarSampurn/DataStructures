#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *queue;
    int size;
    int front;
    int rear;
} Queue;

Queue* createQueue(int size) {
    Queue* q = malloc(sizeof(Queue));
    q->queue = malloc(size * sizeof(int));
    q->size = size;
    q->front = -1;
    q->rear = -1;
    return q;
}

void destroyQueue(Queue* q) {
    free(q->queue);
    free(q);
}

int isFull(Queue* q) {
    return ((q->front == 0 && q->rear == q->size - 1) || (q->rear == (q->front - 1) % (q->size - 1)));
}

int isEmpty(Queue* q) {
    return (q->front == -1);
}

void enqueue(Queue* q, int x) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;

    q->rear = (q->rear + 1) % q->size;
    q->queue[q->rear] = x;
}

int dequeue(Queue* q) {
    int data;

    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }

    data = q->queue[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % q->size;
    }

    return data;
}

void display(Queue* q) {
    int i;

    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    i = q->front;
    do {
        printf("%d ", q->queue[i]);
        i = (i + 1) % q->size;
    } while (i != (q->rear + 1) % q->size);
    printf("\n");
}

int main() {
    int size;
    printf("Enter the size of the queue: ");
    scanf("%d", &size);

    Queue* q = createQueue(size);
    int choice, x;

    do {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &x);
                enqueue(q, x);
                break;
            case 2:
                x = dequeue(q);
                if (x != -1)
                    printf("Dequeued element: %d\n", x);
                break;
            case 3:
                display(q);
                break;
            case 4:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    destroyQueue(q);
    return 0;
}
