#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#define TRUE 1
#define FALSE 0
// Function prototypes
void insertEdge(int graph[MAX][MAX], int u, int v);
void deleteEdge(int graph[MAX][MAX], int u, int v);
int searchEdge(int graph[MAX][MAX], int u, int v);
void BFS(int graph[MAX][MAX], int start);
void DFS(int graph[MAX][MAX], int start);
void DFSUtil(int graph[MAX][MAX], int start,
             int visited[MAX]);

int main()
{
    // Initialize adjacency matrix to 0
    int graph[MAX][MAX] = { 0 };
    // Add edges
    insertEdge(graph, 0, 1);
    insertEdge(graph, 0, 2);
    insertEdge(graph, 1, 2);
    insertEdge(graph, 2, 0);
    insertEdge(graph, 2, 3);
    // Perform BFS
    printf("BFS starting from node 2:\n");
    BFS(graph, 2);
    // Perform DFS
    printf("DFS starting from node 2:\n");
    DFS(graph, 2);
    return 0;
}
// Function to insert an edge into the graph
void insertEdge(int graph[MAX][MAX], int u, int v)
{
    // Set the edge from u to v
    graph[u][v] = 1;
    // Set the edge from v to u (undirected graph)
    graph[v][u] = 1;
}
// Function to delete an edge from the graph
void deleteEdge(int graph[MAX][MAX], int u, int v)
{
    // Remove the edge from u to v
    graph[u][v] = 0;
    // Remove the edge from v to u (undirected graph)
    graph[v][u] = 0;
}
// Function to search for an edge in the graph
int searchEdge(int graph[MAX][MAX], int u, int v)
{
    // Return the existence of edge u-v
    return graph[u][v];
}

// Function to perform BFS traversal
void BFS(int graph[MAX][MAX], int start)
{
    // Initialize visited array
    int visited[MAX] = { 0 };
    int queue[MAX], front = 0, rear = 0;

    // Mark the start node as visited and enqueue it
    visited[start] = TRUE;
    queue[rear++] = start;
    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        // Visit all the adjacent nodes
        for (int i = 0; i < MAX; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = TRUE;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}
// Function to perform DFS traversal
void DFS(int graph[MAX][MAX], int start)
{
    // Initialize visited array
    int visited[MAX] = { 0 };
    DFSUtil(graph, start, visited);
    printf("\n");
}
// Utility function for DFS traversal
void DFSUtil(int graph[MAX][MAX], int start,
             int visited[MAX])
{
    // Mark the current node as visited and print it
    visited[start] = TRUE;
    printf("%d ", start);

    // Visit all the adjacent nodes
    for (int i = 0; i < MAX; i++) {
        if (graph[start][i] == 1 && !visited[i]) {
            DFSUtil(graph, i, visited);
        }
    }
}
