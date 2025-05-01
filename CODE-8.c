#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

int isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}

void enqueue(struct Queue* queue, int item) {
    struct Node* newNode = createNode(item);
    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
        queue->rear->next = queue->front; // Point rear to front for circularity
    } else {
        newNode->next = queue->front;
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("Enqueued %d\n", item);
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Linked Circular Queue is empty\n");
        return -1;
    }
    int item = queue->front->data;
    struct Node* temp = queue->front;
    if (queue->front == queue->rear) {
        queue->front = NULL;
        queue->rear = NULL;
    } else {
        queue->front = queue->front->next;
        queue->rear->next = queue->front; // Update rear's next
    }
    free(temp);
    printf("Dequeued %d\n", item);
    return item;
}

void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Linked Circular Queue is empty\n");
        return;
    }
    printf("Elements in Linked Circular Queue are: ");
    struct Node* current = queue->front;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != queue->front);
    printf("\n");
}

int main() {
    int num_elements, element, i;
    struct Queue* cq = createQueue();

    printf("Enter the number of elements to enqueue: ");
    scanf("%d", &num_elements);

    printf("Enter %d elements to enqueue:\n", num_elements);
    for (i = 0; i < num_elements; i++) {
        scanf("%d", &element);
        enqueue(cq, element);
    }

    printf("\nQueue after enqueues:\n");
    display(cq);

    printf("\nPerforming some dequeues:\n");
    dequeue(cq);
    dequeue(cq);
    printf("Queue after dequeues:\n");
    display(cq);

    printf("\nTrying to enqueue more elements:\n");
    printf("Enter the number of elements to enqueue: ");
    scanf("%d", &num_elements);
    printf("Enter %d elements to enqueue:\n", num_elements);
    for (i = 0; i < num_elements; i++) {
        scanf("%d", &element);
        enqueue(cq, element);
    }
    display(cq);

    // No need to free individual nodes in this basic example,
    // but in a more complex scenario, you would want to.
    free(cq);
    return 0;
}
