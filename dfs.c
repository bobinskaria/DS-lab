#include <stdio.h>
#include <stdlib.h>
#define max 20
struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adj[max];
int visited[max];

void addEdge(int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

void DFS(int v) {
    struct Node* temp;
    visited[v] = 1;
    printf("%d ", v);

    temp = adj[v];
    while (temp != NULL) {
        if (!visited[temp->vertex]) {
            DFS(temp->vertex);
        }
        temp = temp->next;
    }
}

int main() {
    int vertices, edges, u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize adjacency list and visited array
    for (int i = 0; i < vertices; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
        addEdge(v, u); // remove for directed graph
    }

    printf("Enter starting vertex for DFS: ");
    scanf("%d", &start);

    printf("DFS Traversal: ");
    DFS(start);

    return 0;
}
