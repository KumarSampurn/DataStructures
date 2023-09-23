#include<stdio.h>

#define MAX 10
int array[MAX]={0};

int insert(int front, int rear, int x){
    if((front+1)%6==rear){
        printf("array is full");
        return 999;
    }
    array[front] = x;
    front = (front+1)%6;
    return front;
}



int remove(int front, int rear, int x){
    if (front==rear){
        printf("array is empty");
        return 0;
    }
    rear = (rear+1)%6;
    return rear;
}
void display(int front, int rear) {
    if (front == rear) {
        printf("array is empty\n");
        return;
    }

    printf("array elements: ");
    int i = rear;
    while (i != front) {
        printf("%d ", array[i]);
        i = (i + 1) % 6;
    }
    printf("\n");
}



int main() {
    int front = 0;
    int rear = 0;
    int choice, x;

    do {
        printf("1. insert\n");
        printf("2. remove\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &x);
                front = insert(front, rear, x);
                break;
            case 2:
                rear = remove(front, rear, x);
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