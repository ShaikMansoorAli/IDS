#include <stdio.h>
#define MAX_VERTICES 10
int adj[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];
void dfs(int vertex, int n)
{
    visited[vertex] = 1;
    printf("%d", vertex);
    for (int i = 0; i <= n; i++)
    {
        if (adj[vertex][i] == 1 && !visited[i])
        {
            dfs(i, n);
        }
    }
}
int main()
{
    int n, e;
    printf("Enter no of vertices:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    printf("Enter no of edges: ");
    scanf("%d", &e);
    for (int i = 0; i < e; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    int startVertex;
    printf("Starting Index: ");
    scanf("%d", &startVertex);
    dfs(startVertex, n);
    return 0;
}