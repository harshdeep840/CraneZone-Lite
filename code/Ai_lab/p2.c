#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

typedef struct Queue {
    int items[MAX_NODES];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue* q) {
    return q->front == -1;
}

void enqueue(Queue* q, int value) {
    if (q->rear == MAX_NODES - 1) {
        printf("Queue is full!\n");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        int item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
        return item;
    }
}

void bfs(int graph[MAX_NODES][MAX_NODES], int start, int num_nodes) {
   
    int visited[MAX_NODES] = {0};
    
    Queue q;
    initQueue(&q);

    visited[start] = 1;
    enqueue(&q, start);

    printf("BFS traversal order: ");
    
    while (!isEmpty(&q)) {
        int node = dequeue(&q);
        printf("%d ", node);
        
        for (int i = 0; i < num_nodes; i++) {
            if (graph[node][i] == 1 && !visited[i]) {  
                visited[i] = 1;  
                enqueue(&q, i); 
            }
        }
    }
    printf("\n");
}

int main() {
    
    int graph[MAX_NODES][MAX_NODES] = {0};
    
    int num_nodes = 5;

    graph[0][1] = 1; graph[1][0] = 1; 
    graph[0][2] = 1; graph[2][0] = 1; 
    graph[1][3] = 1; graph[3][1] = 1; 
    graph[1][4] = 1; graph[4][1] = 1; 

    bfs(graph, 0, num_nodes);
    
    return 0;
}
