#include <stdio.h>

struct Edge {
    int u, v, w;
};

int find(int parent[], int x) {
    while (parent[x] != x)
        x = parent[x];
    return x;
}

void unionSet(int parent[], int a, int b) {
    parent[b] = a;
}

int main() {
    int V, E;
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    struct Edge edges[E];

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < E; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);

    // Sort edges by weight (simple bubble sort)
    for (int i = 0; i < E - 1; i++)
        for (int j = 0; j < E - i - 1; j++)
            if (edges[j].w > edges[j + 1].w) {
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }

    int parent[V];
    for (int i = 0; i < V; i++)
        parent[i] = i;

    printf("\nMST Edges:\n");
    int total = 0, count = 0;

    for (int i = 0; i < E && count < V - 1; i++) {
        int a = find(parent, edges[i].u);
        int b = find(parent, edges[i].v);

        if (a != b) {
            printf("%d -- %d  (weight=%d)\n",
                   edges[i].u, edges[i].v, edges[i].w);
            total += edges[i].w;
            count++;
            unionSet(parent, a, b);
        }
    }

    printf("\nTotal weight of MST = %d\n", total);

    return 0;
}
