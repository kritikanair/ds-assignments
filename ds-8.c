#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
};

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));
    for (int i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void deleteEdge(struct Graph* graph, int src, int dest) {
    struct Node* temp = graph->adjLists[src];
    struct Node* prev = NULL;
    while (temp != NULL && temp->vertex != dest) {
        prev = temp;
        temp = temp->next;
    }
    if (temp != NULL) {
        if (prev != NULL)
            prev->next = temp->next;
        else
            graph->adjLists[src] = temp->next;
        free(temp);
    }
    temp = graph->adjLists[dest];
    prev = NULL;
    while (temp != NULL && temp->vertex != src) {
        prev = temp;
        temp = temp->next;
    }
    if (temp != NULL) {
        if (prev != NULL)
            prev->next = temp->next;
        else
            graph->adjLists[dest] = temp->next;
        free(temp);
    }
}

void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        struct Node* temp = graph->adjLists[i];
        printf("Vertex %d: ", i);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    struct Graph* graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);

    printf("Deleting edge 1-4\n");
    deleteEdge(graph, 1, 4);
    printGraph(graph);

    return 0;
}