#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

int isFull(struct Queue* queue) {
    return (queue->rear == MAX_SIZE - 1);
}


int isEmpty(struct Queue* queue) {
    return (queue->front == -1 && queue->rear == -1);
}


void enQueue(struct Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full\n");
    } else {
        if (isEmpty(queue)) {
            queue->front = 0;
        }
        queue->rear++;
        queue->items[queue->rear] = value;
    }
}


void deQueue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
    } else {
        if (queue->front == queue->rear) {
            queue->front = -1;
            queue->rear = -1;
        } else {
            queue->front++;
        }
    }
}

int main() {
    struct Queue* queue = createQueue();
    enQueue(queue, 10);
    enQueue(queue, 20);
    deQueue(queue);
    enQueue(queue, 30);
    enQueue(queue, 40);
    deQueue(queue);
    printf("Front element: %d\n", queue->items[queue->front]);
    printf("Rear element: %d\n", queue->items[queue->rear]);
    return 0;
}