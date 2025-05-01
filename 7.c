#include <stdio.h>
#include <stdlib.h>

struct CircularQueue {
    int *arr;
    int front;
    int rear;
    int size;
};

void initializeQueue(struct CircularQueue *queue, int size) {
    queue->size = size;
    queue->arr = (int *)malloc(queue->size * sizeof(int));
    queue->front = -1;
    queue->rear = -1;
}

int isFull(struct CircularQueue *queue) {
    return (queue->front == (queue->rear + 1) % queue->size);
}

int isEmpty(struct CircularQueue *queue) {
    return (queue->front == -1);
}

void enqueue(struct CircularQueue *queue, int data) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue element.\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % queue->size;
    queue->arr[queue->rear] = data;
    printf("%d enqueued to queue\n", data);
}

int dequeue(struct CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue element.\n");
        return -1;
    }
    int data = queue->arr[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % queue->size;
    }
    printf("%d dequeued from queue\n", data);
    return data;
}

void displayQueue(struct CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    int i = queue->front;
    while (i != queue->rear) {
        printf("%d ", queue->arr[i]);
        i = (i + 1) % queue->size;
    }
    printf("%d\n", queue->arr[i]);
}

int main() {
    int size, choice, data;
    struct CircularQueue queue;

    printf("Enter the size of the circular queue: ");
    scanf("%d", &size);
    initializeQueue(&queue, size);

    do {
        printf("\nCircular Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(&queue, data);
                break;
            case 2:
                dequeue(&queue);
                break;
            case 3:
                displayQueue(&queue);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    free(queue.arr);
    return 0;
}
