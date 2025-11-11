#include <stdio.h>
#define SIZE 5

int items[SIZE];
int front = -1, rear = -1;

int isfull() {
    return ((front == rear + 1) || (front == 0 && rear == SIZE - 1));
}

int isempty() {
    return (front == -1);
}

void enqueue(int element) {
    if (isfull()) {
        printf("\nQueue is full!!\n");
    } else {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % SIZE;
        items[rear] = element;
        printf("\n Inserted element -> %d", element);
    }
}

int dequeue() {
    int element;
    if (isempty()) {
        printf("\nQueue is empty!!\n");
        return -1;
    } else {
        element = items[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
        printf("\nDeleted element -> %d\n", element);
        return element;
    }
}

void display() {
    int i;
    if (isempty()) {
        printf("\nEmpty Queue\n");
    } else {
        printf("\nFront -> %d", front);
        printf("\nItems -> ");
        for (i = front; i != rear; i = (i + 1) % SIZE) {
            printf("%d ", items[i]);
        }
        printf("%d", items[i]); // Print last element
        printf("\nRear -> %d\n", rear);
    }
}

int main() {
    int choice, value;

    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
