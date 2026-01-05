#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adj[20];
int visited[20];
int stack[20];
int top = -1;

void push(int v) {
    stack[++top] = v;
}

void addEdge(int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

void DFS(int v) {
    visited[v] = 1;

    struct Node* temp = adj[v];
    while (temp != NULL) {
        if (!visited[temp->vertex]) {
            DFS(temp->vertex);
        }
        temp = temp->next;
    }

    push(v);   // push after visiting all children
}

int main() {
    int vertices, edges, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < vertices; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    printf("Enter edges (u v) for a Directed Graph:\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);  // directed edge
    }

    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            DFS(i);
        }
    }

    printf("Topological Order: ");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }

    return 0;
}
