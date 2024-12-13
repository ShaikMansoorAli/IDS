#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int adj[MAX][MAX]; 


void bfs(int start, int n) {
    int queue[MAX], front = -1, rear = -1;
    int visited[MAX] = {0};


    queue[++rear] = start;
    visited[start] = 1;

    printf("BFS Traversal: ");
    while (front != rear) {
 
        front++;
        int vertex = queue[front];
        printf("%d ", vertex);

 
        for (int i = 0; i < n; i++) {
            if (adj[vertex][i] == 1 && !visited[i]) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int n, e, u, v, vertex;

 
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    if (n <= 0 || n > MAX) {
        printf("Invalid number of vertices! Please use 1 to %d vertices.\n", MAX);
        return 1;
    }

  
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

    printf("Enter Starting Vertex: ");
    scanf("%d", &vertex);
    bfs(vertex, n);

    return 0;
}
