#include <stdio.h>
#define MAX 10

int adj[MAX][MAX];


void BFS(int queue[MAX], int *front, int *rear, int visited[MAX], int n) {
 
    if (*front == *rear) {
        return;
    }


    int vertex = queue[(*front)++];
    printf("%d ", vertex);

  
    for (int i = 0; i < n; i++) {
        if (adj[vertex][i] == 1 && !visited[i]) {
            visited[i] = 1;
            queue[(*rear)++] = i;
        }
    }

 
    BFS(queue, front, rear, visited, n);
}

int main() {
    int n, e, u, v;


    printf("Enter number of vertices: ");
    scanf("%d", &n);

 
    printf("Enter number of edges: ");
    scanf("%d", &e);

 
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            adj[i][j] = 0;
        }
    }

 
    printf("Enter edges (u v):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

 
    int visited[MAX] = {0};
    int queue[MAX], front = 0, rear = 0;

  
    visited[0] = 1;
    queue[rear++] = 0;

    printf("BFS Recursive Traversal: ");
    BFS(queue, &front, &rear, visited, n);
    printf("\n");

    return 0;
}
