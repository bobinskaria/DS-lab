#include <stdio.h>
#include <stdlib.h>

struct Node {
    int v, w;
    struct Node* next;
};

struct Node* adj[20];
int visited[20];

void addEdge(int u, int v, int w) {
    struct Node* n1 = (struct Node*)malloc(sizeof(struct Node));
    n1->v = v;
    n1->w = w;
    n1->next = adj[u];
    adj[u] = n1;

    struct Node* n2 = (struct Node*)malloc(sizeof(struct Node));
    n2->v = u;
    n2->w = w;
    n2->next = adj[v];
    adj[v] = n2;
}

int main() {
    int n, e, u, v, w;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    for (int i = 1; i <= n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    printf("Enter edges (u v weight):\n");
    for (int i = 1; i <= e; i++) {
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    int total = 0;
    visited[1] = 1;      // Start from vertex 1
    int count = 1;

    printf("Edges in MST:\n");

    while (count < n) {
        int min = 99999, from = -1, to = -1;

        for (u = 1; u <= n; u++) {
            if (visited[u]) {
                struct Node* temp = adj[u];
                while (temp != NULL) {
                    if (!visited[temp->v] && temp->w < min) {
                        min = temp->w;
                        from = u;
                        to = temp->v;
                    }
                    temp = temp->next;
                }
            }
        }

        printf("%d -> %d  cost = %d\n", from, to, min);
        total += min;
        visited[to] = 1;
        count++;
    }

    printf("Total Minimum Cost = %d\n", total);

    return 0;
}
