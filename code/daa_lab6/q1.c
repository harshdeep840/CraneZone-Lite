#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100

void read_adjacency_matrix(const char *filename, int adjacency_matrix[MAX_VERTICES][MAX_VERTICES], int *num_vertices) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    *num_vertices = 0;
    while (*num_vertices < MAX_VERTICES) {
        for (int j = 0; j < *num_vertices + 1; j++) {
            if (j == *num_vertices) {
                if (fscanf(file, "%d", &adjacency_matrix[*num_vertices][*num_vertices]) == EOF) {
                    fclose(file);
                    return; // Stop reading if end of file is reached
                }
            } else {
                if (fscanf(file, "%d", &adjacency_matrix[*num_vertices][j]) == EOF) {
                    fclose(file);
                    return; // Stop reading if end of file is reached
                }
            }
        }
        (*num_vertices)++;
    }

    fclose(file);
}

void prim_mst(int adjacency_matrix[MAX_VERTICES][MAX_VERTICES], int num_vertices, int start_vertex,
               int mst_matrix[MAX_VERTICES][MAX_VERTICES], int *total_cost) {
    int visited[MAX_VERTICES] = {0};
    int min_edge[MAX_VERTICES];
    *total_cost = 0;

    for (int i = 0; i < num_vertices; i++) {
        min_edge[i] = INT_MAX;
    }

    visited[start_vertex] = 1;
    min_edge[start_vertex] = 0;

    for (int count = 0; count < num_vertices - 1; count++) {
        int u = -1;

        // Find the minimum edge
        for (int i = 0; i < num_vertices; i++) {
            if (!visited[i] && (u == -1 || min_edge[i] < min_edge[u])) {
                u = i;
            }
        }

        visited[u] = 1;
        *total_cost += min_edge[u];

        for (int v = 0; v < num_vertices; v++) {
            if (adjacency_matrix[u][v] && !visited[v] && adjacency_matrix[u][v] < min_edge[v]) {
                min_edge[v] = adjacency_matrix[u][v];
                mst_matrix[u][v] = adjacency_matrix[u][v];
                mst_matrix[v][u] = adjacency_matrix[u][v];  // Undirected graph
            }
        }
    }
}

void display_adjacency_matrix(int matrix[MAX_VERTICES][MAX_VERTICES], int num_vertices) {
    printf("Cost Adjacency Matrix of the Minimum Spanning Tree:\n");
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int adjacency_matrix[MAX_VERTICES][MAX_VERTICES] = {0};
    int mst_matrix[MAX_VERTICES][MAX_VERTICES] = {0};
    int num_vertices, total_cost;

    const char *filename = "numbers.txt"; // Adjust this if needed
    read_adjacency_matrix(filename, adjacency_matrix, &num_vertices);
    prim_mst(adjacency_matrix, num_vertices, 0, mst_matrix, &total_cost);

    display_adjacency_matrix(mst_matrix, num_vertices);
    printf("Total cost of the Minimum Spanning Tree: %d\n", total_cost);

    return 0;
}
