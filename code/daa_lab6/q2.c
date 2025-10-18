#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, w;
} Edge;

typedef struct {
    Edge *edges;
    int num_edges;
} Graph;

int compare(const void *a, const void *b) {
    Edge *edge1 = (Edge *)a;
    Edge *edge2 = (Edge *)b;
    return edge1->w - edge2->w; // Sort edges by weight
}

int find(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

void union_sets(int parent[], int x, int y) {
    parent[x] = y;
}

void kruskal(Graph *graph, int n) {
    int parent[n];
    for (int i = 0; i < n; i++)
        parent[i] = -1;

    qsort(graph->edges, graph->num_edges, sizeof(graph->edges[0]), compare);

    printf("Selected edges in the Minimum Spanning Tree:\n");
    int total_cost = 0;

    for (int i = 0; i < graph->num_edges; i++) {
        Edge edge = graph->edges[i];
        int set_u = find(parent, edge.u);
        int set_v = find(parent, edge.v);

        if (set_u != set_v) {
            printf("Edge (%d, %d) with weight %d\n", edge.u + 1, edge.v + 1, edge.w);
            total_cost += edge.w;
            union_sets(parent, set_u, set_v);
        }
    }

    printf("Total cost of the Minimum Spanning Tree: %d\n", total_cost);
}

int main() {
    int n, m;

    printf("Enter the number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    Graph graph;
    graph.edges = (Edge *)malloc(m * sizeof(Edge));
    graph.num_edges = m;

    printf("Enter each edge in the format (u, v, w):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &graph.edges[i].u, &graph.edges[i].v, &graph.edges[i].w);
        graph.edges[i].u--; // To make zero-indexed
        graph.edges[i].v--; // To make zero-indexed
    }

    kruskal(&graph, n);

    free(graph.edges);
    return 0;
}
