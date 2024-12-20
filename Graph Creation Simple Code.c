#include <stdio.h>
#include <stdlib.h>

struct AdjListNode {
	int destination;
	struct AdjListNode* next;
};

struct AdjList {
	struct AdjListNode *head;
};

struct Graph {
	int vertex;
	struct AdjList* array;
};

struct AdjListNode* newAdjListNode(int newDestination){
    
struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
	newNode->destination = newDestination;
	newNode->next = NULL;
	return newNode;
}

struct Graph* createGraph(int newVertex){
	 
struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
graph->vertex = newVertex;

graph->array = (struct AdjList*) malloc(newVertex * sizeof(struct AdjList));
  int i;
    for (i = 0; i < newVertex; i++){
		graph->array[i].head = NULL; }
	return graph;
}


void addEdge(struct Graph* graph, int source, int destination){
    
	struct AdjListNode* newNode = newAdjListNode(destination);
	newNode->next = graph->array[source].head;
	graph->array[source].head = newNode;

	newNode = newAdjListNode(source);
	newNode->next = graph->array[destination].head;
	graph->array[destination].head = newNode;
}

void printGraph(struct Graph* graph){
	
	int i;
	for (i = 0; i < graph->vertex; i++){
		struct AdjListNode* temp = graph->array[i].head;
		printf("\n Adjacency list of vertex %d\n head ", i);
		while (temp)
		{
			printf("-> %d", temp->destination);
			temp = temp->next;
		}
		printf("\n");
	}
}
int main(){
    
	int vertex = 5;  
	struct Graph* graph = createGraph(vertex);
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 4);
	addEdge(graph, 1, 2);
	addEdge(graph, 1, 3);
	addEdge(graph, 1, 4);
	addEdge(graph, 2, 3);
	addEdge(graph, 3, 4);
  
	printGraph(graph);

	return 0;
}
