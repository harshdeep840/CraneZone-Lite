#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

int graph[MAX_NODES][MAX_NODES];

int visited[MAX_NODES];

void dfs(int node, int num_nodes) {
    
    visited[node] = 1;

    printf("%d ", node);

    for (int i = 0; i < num_nodes; i++) {
        if (graph[node][i] == 1 && !visited[i]) {  
            dfs(i, num_nodes);  
        }
    }
}

int main() {
    
    int num_nodes = 5;

    graph[0][1] = 1; graph[1][0] = 1; 
    graph[0][2] = 1; graph[2][0] = 1; 
    graph[1][3] = 1; graph[3][1] = 1; 
    graph[1][4] = 1; graph[4][1] = 1; 

    for (int i = 0; i < num_nodes; i++) {
        visited[i] = 0;
    }

    printf("DFS traversal order: ");
    dfs(0, num_nodes);
    printf("\n");

    return 0;
}
