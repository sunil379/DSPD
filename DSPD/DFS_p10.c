#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100 // Define the maximum number of vertices

// Function to perform DFS traversal recursively
void dfs(int graph[MAX][MAX], int vertex, bool visited[], int num_vertices) {
    // Mark the current vertex as visited
    visited[vertex] = true;
    printf("%d ", vertex);

    // Explore all adjacent vertices
    for (int i = 0; i < num_vertices; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            dfs(graph, i, visited, num_vertices);
        }
    }
}

int main() {
    int graph[MAX][MAX];
    int num_vertices, start_vertex;

    // Initialize the graph with zeros
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            graph[i][j] = 0;
        }
    }

    // Input number of vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Input the starting vertex
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &start_vertex);

    // Initialize visited array
    bool visited[MAX] = {false};

    // Perform DFS
    printf("Depth-First Search starting from vertex %d:\n", start_vertex);
    dfs(graph, start_vertex, visited, num_vertices);

    printf("\n");

    return 0;
}
