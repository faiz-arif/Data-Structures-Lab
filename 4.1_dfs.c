#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define V 6

void DFS(int graph[V][V], int start) {
    bool visited[V];
    for (int i = 0; i < V; i++) visited[i] = false;
    // Create a stack for DFS
    int stack[V];
    int top = -1;
    // Push the current source node.
    stack[++top] = start;
    visited[start] = true;
    while (top >= 0) {
        // Pop a vertex from stack and print it
        int current = stack[top--];
        printf("%d\t", current);
        // Get all adjacent vertices of the popped vertex s
        // If a adjacent has not been visited, then push it
        // to the stack.
        for (int i = V-1; i >= 0; i--) {
            if (graph[current][i] && !visited[i]) {
                stack[++top] = i;
                visited[i] = true;
            }
        }
    }
}

int main() {
    int graph[V][V] = {
        {0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0}
    };
    DFS(graph, 0);
    printf("\n");
    return 0;
}

