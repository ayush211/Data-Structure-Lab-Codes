#include <stdio.h>
#define MAX 100 // Maximum size of the queue

int queue[MAX];
int front = -1; // Points to the front element of the queue
int rear = -1;  // Points to the rear element of the queue

// Function to enqueue (insert) an element into the queue
void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue Overflow! Cannot enqueue %d.\n", value);
    } else {
        if (front == -1) { // If the queue is initially empty
            front = 0;
        }
        queue[++rear] = value;
        printf("%d enqueued into the queue.\n", value);
    }
}

// Function to dequeue (remove) an element from the queue
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow! The queue is empty.\n");
    } else {
        printf("%d dequeued from the queue.\n", queue[front++]);
    }
}


// Function to display the elements of the queue
void display() {
    if (front == -1 || front > rear) {
        printf("The queue is empty.\n");
    } else {
        printf("Queue elements are:\n");
    for (int i = front; i <= rear; i++) {
    printf("%d ", queue[i]);
    }
    printf("\n");
    }
}

// Main function
int main() {
    int choice, value;

    while (1) {
        printf("\nQueue Operations using Array:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
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
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
