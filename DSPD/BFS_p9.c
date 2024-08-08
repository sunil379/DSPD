#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100 // Define the maximum number of vertices

// Queue structure for BFS
typedef struct {
    int items[MAX];
    int front, rear;
} Queue;

// Function to initialize the queue
void initialize_queue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is empty
bool is_empty(Queue *q) {
    return q->front == -1;
}

// Function to check if the queue is full
bool is_full(Queue *q) {
    return q->rear == MAX - 1;
}

// Function to enqueue an element
void enqueue(Queue *q, int value) {
    if (is_full(q)) {
        printf("Queue is full!\n");
        return;
    }
    if (is_empty(q)) {
        q->front = 0;
    }
    q->items[++(q->rear)] = value;
}

// Function to dequeue an element
int dequeue(Queue *q) {
    if (is_empty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int value = q->items[q->front];
    if (q->front >= q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return value;
}

// Function to perform BFS on the graph
void bfs(int graph[MAX][MAX], int start_vertex, int num_vertices) {
    bool visited[MAX] = {false}; // Array to keep track of visited vertices
    Queue q;
    initialize_queue(&q);

    // Start with the initial vertex
    visited[start_vertex] = true;
    enqueue(&q, start_vertex);

    printf("Breadth-First Search starting from vertex %d:\n", start_vertex);

    while (!is_empty(&q)) {
        int vertex = dequeue(&q);
        printf("%d ", vertex);

        // Explore all adjacent vertices
        for (int i = 0; i < num_vertices; i++) {
            if (graph[vertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                enqueue(&q, i);
            }
        }
    }
    printf("\n");
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
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &start_vertex);

    // Perform BFS
    bfs(graph, start_vertex, num_vertices);

    return 0;
}
