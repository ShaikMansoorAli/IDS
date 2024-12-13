#include <stdio.h>
#define MAX 10

int adj[MAX][MAX];


void dfs(int start, int n) {
    int stack[MAX];
    int top = -1;
    int visited[MAX] = {0}; 

 
    stack[++top] = start;
    visited[start] = 1;

    printf("BFS Traversal: ");
    while (top != -1) { 
        int vertex = stack[top--];
        printf("%d ", vertex);

      
        for (int i = 0; i < n; i++) {
            if (adj[vertex][i] == 1 && !visited[i]) {
                stack[++top] = i; 
                visited[i] = 1;   
            }
        }
    }
    printf("\n");
}

int main() {
    int n, e;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

   
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter edges (u v for an edge between u and v):\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    int startVertex;
    printf("Enter starting vertex: ");
    scanf("%d", &startVertex);

    dfs(startVertex, n);

    return 0;
}
