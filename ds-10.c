#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 100

int graph[MAX][MAX];
int vertices;

// Function to find the minimum key vertex from the set of vertices not yet included in MST
int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, minIndex;

    for (int v = 0; v < vertices; v++)
        if (mstSet[v] == false && key[v] < min) {
            min = key[v];
            minIndex = v;
        }

    return minIndex;
}

// Function to print the constructed MST
void printMST(int parent[]) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < vertices; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}

// Function to implement Prim's algorithm
void primMST() {
    int parent[MAX];      // Array to store constructed MST
    int key[MAX];         // Key values used to pick minimum weight edge
    bool mstSet[MAX];     // To represent the set of vertices included in MST

    // Initialize all keys as infinite
    for (int i = 0; i < vertices; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    // Include the first vertex in MST
    key[0] = 0;      // Make key 0 so that this vertex is picked as the first vertex
    parent[0] = -1;  // First node is always the root of MST

    // The MST will have `vertices - 1` edges
    for (int count = 0; count < vertices - 1; count++) {
        int u = minKey(key, mstSet); // Pick the minimum key vertex
        mstSet[u] = true;            // Add the picked vertex to the MST set

        // Update key values and parent index of adjacent vertices
        for (int v = 0; v < vertices; v++) {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent);
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the adjacency matrix (enter 0 if no edge exists):\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    primMST();

    return 0;
}
