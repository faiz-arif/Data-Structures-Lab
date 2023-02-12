#include<stdio.h>
#include <limits.h>
#define INFINITY 9999
//#define V 7

int minDistance(int dist[], int visited[], int V)
{
    int min = INT_MAX, min_index;
  
    for (int v = 0; v < V; v++)
        if (visited[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;
  
    return min_index;
}

void dijkstra(int graph[7][7], int src, int V)
{
    int dist[V];
    int visited[V];

    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
  
    dist[src] = 0;
  
    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, visited, V);
  
        visited[u] = 1;
  
        for (int v = 0; v < V; v++)
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
  
    printf("Vertex \t Distance from Source\n");
  
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

int main()
{
    int G[7][7], i, j, n, u;
    printf("Enter no. of vertices:");
    scanf("%d", & n);
    printf("\nEnter the adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("enter the distance between %d and %d :", i, j);
            scanf("%d", & G[i][j]);
        }
        printf("\n");
    }
    printf("\nEnter the starting node:");
    scanf("%d", & u);
    dijkstra(G, u, n);
    return 0;
}

