#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

int V = 100;

typedef enum GraphTypes
{
    DIRECTED, // DEFAULT
    UNDIRECTED,
    WEIGHTED
} GraphTypes;

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Graph
{
    GraphTypes type;
    int numVertices;
    Node **adjLists;
} Graph;

Graph *createGraph(int);

void addEdge(Graph *, int, int);

void DFS(Graph *, int, bool *);

void BFS(Graph *, int);

void showGraph(Graph *);

Graph *graphFromMatrix(int [V][V], int);

Graph *graphFromList(Node **, int);

void topologicalSort(Graph *);

int **graphToMatrix(Graph *);