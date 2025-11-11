#include <stdio.h>
#include <stdlib.h>

#define SIZE 5  // Maximum size of the queue

int items[SIZE];
int front = -1, rear = -1;

int isFull() {
    return rear == SIZE - 1;
}

int isEmpty() {
    return (front == -1 || front > rear);
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full! Cannot enqueue %d\n", value);
        return;
    }
    if (front == -1)
        front = 0;
    rear++;
    items[rear] = value;
    printf("%d enqueued to queue.\n", value);
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty! Cannot dequeue.\n");
        return;
    }
    printf("%d dequeued from queue.\n", items[front]);
    front++;
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements are: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", items[i]);
    printf("\n");
}

void peek() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Front element is: %d\n", items[front]);
}

int main() {
    int choice, value;

    printf("----- Queue Using Array (C Version) -----\n");

    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Peek\n5. Exit\n");
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
                peek();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
