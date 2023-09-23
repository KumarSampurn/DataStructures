#include<stdio.h>
int queue[6]={0};

int enqueue(int front, int rear, int x){
    if((front+1)%6==rear){
        printf("Queue is full");
        return 999;
    }
    queue[front] = x;
    front = (front+1)%6;
    return front;
}



int dequeue(int front, int rear, int x){
    if (front==rear){
        printf("Queue is empty");
        return 0;
    }
    rear = (rear+1)%6;
    return rear;
}
void display(int front, int rear) {
    if (front == rear) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    int i = rear;
    while (i != front) {
        printf("%d ", queue[i]);
        i = (i + 1) % 6;
    }
    printf("\n");
}



int main() {
    int front = 0;
    int rear = 0;
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
                front = enqueue(front, rear, x);
                break;
            case 2:
                rear = dequeue(front, rear, x);
                break;
            case 3:
                display(front, rear);
                break;
            case 4:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}