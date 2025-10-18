#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define V 5 

int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void primMST(int graph[V][V]) {
    int parent[V], key[V];
    bool mstSet[V] = {false};

    // Initialize keys to INFINITY and parent array
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        parent[i] = -1;
    }

    key[0] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        // Update the keys and parent indices of adjacent vertices
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    int mstCost = 0;
    printf("Cost Adjacency Matrix of the Minimum Spanning Tree:\n");
    int mstAdjMatrix[V][V] = {0}; 

    for (int i = 1; i < V; i++) {
        mstAdjMatrix[parent[i]][i] = graph[parent[i]][i];
        mstAdjMatrix[i][parent[i]] = graph[parent[i]][i]; 
        mstCost += graph[parent[i]][i];
    }

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d ", mstAdjMatrix[i][j]);
        }
        printf("\n");
    }

    printf("Total cost of the Minimum Spanning Tree: %d\n", mstCost);
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph);
    return 0;
}
