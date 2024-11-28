#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#define TRUE 1
#define FALSE 0

void insertEdge(int graph[MAX][MAX], int u, int v);
void deleteEdge(int graph[MAX][MAX], int u, int v);
int searchEdge(int graph[MAX][MAX], int u, int v);
void BFS(int graph[MAX][MAX], int start);
void DFS(int graph[MAX][MAX], int start);
void DFSUtil(int graph[MAX][MAX], int start,
             int visited[MAX]);

int main()
{
    int graph[MAX][MAX] = { 0 };
    
    insertEdge(graph, 0, 1);
    insertEdge(graph, 0, 2);
    insertEdge(graph, 1, 2);
    insertEdge(graph, 2, 0);
    insertEdge(graph, 2, 3);
    
    printf("BFS starting from node 2:\n");
    BFS(graph, 2);
    
    printf("DFS starting from node 2:\n");
    DFS(graph, 2);
  
    return 0;
}

void insertEdge(int graph[MAX][MAX], int u, int v)
{
    
    graph[u][v] = 1;
    // undirected graph
    graph[v][u] = 1;
}

void deleteEdge(int graph[MAX][MAX], int u, int v)
{
  
    graph[u][v] = 0;
    //undirected graph
    graph[v][u] = 0;
}

int searchEdge(int graph[MAX][MAX], int u, int v)
{
    
    return graph[u][v];
}
void BFS(int graph[MAX][MAX], int start)
{
    
    int visited[MAX] = { 0 };
    int queue[MAX], front = 0, rear = 0;

    visited[start] = TRUE;
    queue[rear++] = start;
    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        for (int i = 0; i < MAX; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = TRUE;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}
void DFS(int graph[MAX][MAX], int start)
{
    int visited[MAX] = { 0 };
    DFSUtil(graph, start, visited);
    printf("\n");
}
void DFSUtil(int graph[MAX][MAX], int start,
             int visited[MAX])
{
    visited[start] = TRUE;
    printf("%d ", start);

    for (int i = 0; i < MAX; i++) {
        if (graph[start][i] == 1 && !visited[i]) {
            DFSUtil(graph, i, visited);
        }
    }
}
