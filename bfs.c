#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adj[20];
int visited[20];
int queue[20], front = -1, rear = -1;

void enqueue(int v) {
    if (rear == 19) return;  
    if (front == -1) front = 0;
    queue[++rear] = v;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

void addEdge(int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

void BFS(int start) {
    int v;
    enqueue(start);
    visited[start] = 1;

    while ((v = dequeue()) != -1) {
        printf("%d ", v);

        struct Node* temp = adj[v];
        while (temp != NULL) {
            if (!visited[temp->vertex]) {
                enqueue(temp->vertex);
                visited[temp->vertex] = 1;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int vertices, edges, u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < vertices; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);  // remove this for directed graph
    }

    printf("Enter starting vertex for BFS: ");
    scanf("%d", &start);

    printf("BFS Traversal: ");
    BFS(start);

    return 0;
}
