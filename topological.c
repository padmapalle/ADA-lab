/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure to represent a vertex/node in the graph
typedef struct Node {
    int value;
    struct Node* next;
} Node;

// Structure to represent a directed graph
typedef struct Graph {
    int numVertices;
    Node* adjacencyList[MAX_VERTICES];
} Graph;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with a given number of vertices
Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;

    for (int i = 0; i < numVertices; ++i)
        graph->adjacencyList[i] = NULL;

    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;
}

// Recursive function to perform DFS
void topologicalSortDFS(Graph* graph, int vertex, int visited[], int* stack, int* index) {
    visited[vertex] = 1;

    Node* currentNode = graph->adjacencyList[vertex];
    while (currentNode != NULL) {
        int adjacentVertex = currentNode->value;

        if (!visited[adjacentVertex])
            topologicalSortDFS(graph, adjacentVertex, visited, stack, index);

        currentNode = currentNode->next;
    }

    stack[*index] = vertex;
    (*index)--;
}

// Function to perform topological sort using DFS
void topologicalSort(Graph* graph) {
    int visited[MAX_VERTICES] = { 0 };
    int stack[MAX_VERTICES];
    int index = graph->numVertices - 1;

    for (int i = 0; i < graph->numVertices; ++i) {
        if (!visited[i])
            topologicalSortDFS(graph, i, visited, stack, &index);
    }

    printf("Topological Ordering: ");
    for (int i = 0; i < graph->numVertices; ++i)
        printf("%d ", stack[i]);
    printf("\n");
}

int main() {
    int numVertices, numEdges;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);

    Graph* graph = createGraph(numVertices);

    printf("Enter the number of edges in the graph: ");
    scanf("%d", &numEdges);

    printf("Enter the edges (source vertex and destination vertex):\n");
    for (int i = 0; i < numEdges; ++i) {
        int src, dest;
        scanf("%d%d", &src, &dest);
        addEdge(graph, src, dest);
    }

    topologicalSort(graph);

    return 0;
}
