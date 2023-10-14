#include "graph.h"

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

Graph *createGraph(int vertices)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->type = DIRECTED;
    graph->adjLists = (Node **)malloc(vertices * sizeof(Node *));

    for (int i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

void addEdge(Graph *graph, int src, int dest)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = dest;
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    if (graph->type == UNDIRECTED)
    {
        newNode = (Node *)malloc(sizeof(Node));
        newNode->data = src;
        newNode->next = graph->adjLists[dest];
        graph->adjLists[dest] = newNode;
    }
}

void DFS(Graph *graph, int vertex, bool *visited)
{
    visited[vertex] = true;
    printf("%d ", vertex);

    Node *adjList = graph->adjLists[vertex];
    while (adjList)
    {
        int neighbor = adjList->data;
        if (!visited[neighbor])
            DFS(graph, neighbor, visited);
        adjList = adjList->next;
    }
}

void BFS(Graph *graph, int startVertex)
{
    bool visited[graph->numVertices];
    for (int i = 0; i < graph->numVertices; i++)
    {
        visited[i] = false;
    }

    int queue[graph->numVertices];
    int front = 0, rear = 0;

    visited[startVertex] = true;
    queue[rear++] = startVertex;

    printf("Breadth-First Traversal: ");

    while (front < rear)
    {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        Node *temp = graph->adjLists[currentVertex];
        while (temp)
        {
            int adjVertex = temp->data;
            if (!visited[adjVertex])
            {
                visited[adjVertex] = true;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }
}

void showGraph(Graph *graph)
{
    for (int i = 0; i < graph->numVertices; i++)
    {
        Node *current = graph->adjLists[i];
        printf("\e[1;36mVertex \e[4;32m%d\e[0m: ", i);
        while (current)
        {
            printf("(\e[1;31m%d\e[0m)\e[1;36m -> ", current->data);
            current = current->next;
        }
        printf("\e[1;31mNULL\e[0m\n");
    }
}

Graph *graphFromMatrix(int graph[V][V], int V)
{
    Graph *newGraph = (Graph *)malloc(sizeof(Graph));
    newGraph->numVertices = V;
    newGraph->adjLists = (Node **)malloc(V * sizeof(Node *));

    for (int i = 0; i < V; i++)
    {
        newGraph->adjLists[i] = NULL;
        for (int j = 0; j < V; j++)
        {
            if (graph[i][j] == 1)
            {
                Node *newNode = createNode(j);
                newNode->next = newGraph->adjLists[i];
                newGraph->adjLists[i] = newNode;
            }
        }
    }

    return newGraph;
}

Graph *graphFromList(Node *adjacencyList[], int V)
{
    Graph *newGraph = (Graph *)malloc(sizeof(Graph));
    newGraph->numVertices = V;
    newGraph->adjLists = (Node **)malloc(V * sizeof(Node *));

    for (int i = 0; i < V; i++)
    {
        newGraph->adjLists[i] = NULL;
        Node *currentNode = adjacencyList[i];
        while (currentNode)
        {
            Node *newNode = createNode(currentNode->data);
            newNode->next = newGraph->adjLists[i];
            newGraph->adjLists[i] = newNode;
            currentNode = currentNode->next;
        }
    }

    return newGraph;
}

void topologicalSortUtil(Graph *graph, int V, bool visited[V], Node **stack)
{
    visited[V] = true;

    Node *adjList = graph->adjLists[V];
    while (adjList)
    {
        int neighbor = adjList->data;
        if (!visited[neighbor])
            topologicalSortUtil(graph, neighbor, visited, stack);
        adjList = adjList->next;
    }

    Node *newNode = createNode(V);
    newNode->next = *stack;
    *stack = newNode;
}

void topologicalSort(Graph *graph)
{
    bool visited[graph->numVertices];
    for (int i = 0; i < graph->numVertices; i++)
        visited[i] = false;

    Node *stack = NULL;

    for (int i = 0; i < graph->numVertices; i++)
        if (!visited[i])
            topologicalSortUtil(graph, i, visited, &stack);

    printf("Topological Sort: ");
    while (stack)
    {
        printf("%d ", stack->data);
        stack = stack->next;
    }
    printf("\n");
}

int** graphToMatrix(Graph* graph) {
    int numVertices = graph->numVertices;
    int** adjacencyMatrix = (int**)malloc(numVertices * sizeof(int*));

    for (int i = 0; i < numVertices; i++) {
        adjacencyMatrix[i] = (int*)malloc(numVertices * sizeof(int));
        for (int j = 0; j < numVertices; j++)
            adjacencyMatrix[i][j] = 0;
    }

    for (int i = 0; i < numVertices; i++) {
        Node* temp = graph->adjLists[i];
        while (temp) {
            adjacencyMatrix[i][temp->data] = 1;
            temp = temp->next;
        }
    }

    return adjacencyMatrix;
}