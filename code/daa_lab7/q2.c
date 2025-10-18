#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

typedef struct {
    int src, dest, weight;
} Edge;

typedef struct {
    int parent, rank;
} Subset;

int compareEdges(const void* a, const void* b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

// Function to find the parent of an element with path compression
int find(Subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

void unionSubsets(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    } else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

void kruskalMST(Edge edges[], int numEdges, int numVertices) {
    qsort(edges, numEdges, sizeof(edges[0]), compareEdges);
    
    Subset subsets[MAX_VERTICES];
    for (int v = 0; v < numVertices; v++) {
        subsets[v].parent = v; 
        subsets[v].rank = 0;
    }

    printf("Selected edges in the Minimum Spanning Tree:\n");
    int totalCost = 0;

    for (int i = 0; i < numEdges; i++) {
        Edge edge = edges[i];
        int x = find(subsets, edge.src);
        int y = find(subsets, edge.dest);

        if (x != y) { 
            printf("%d -- %d == %d\n", edge.src, edge.dest, edge.weight);
            totalCost += edge.weight;
            unionSubsets(subsets, x, y);
        }
    }

    printf("Total cost of the Minimum Spanning Tree: %d\n", totalCost);
}

int main() {
    Edge edges[] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };
    int numVertices = 4;
    int numEdges = sizeof(edges) / sizeof(edges[0]);

    kruskalMST(edges, numEdges, numVertices);
    return 0;
}
