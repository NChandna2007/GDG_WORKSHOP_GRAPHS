#include <stdio.h>
#include <stdlib.h>

struct AdjListNode {
    int dest;
    struct AdjListNode* next;
};

struct Graph {
    int V;
    struct AdjListNode** array;
};


struct AdjListNode* newAdjListNode(int dest) {
    struct AdjListNode* newNode = malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}


struct Graph* createGraph(int V) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = calloc(V, sizeof(struct AdjListNode*));
    return graph;
}


void addEdge(struct Graph* graph, int src, int dest) {
    
    
    struct AdjListNode* node = newAdjListNode(dest);
    node->next = graph->array[src];
    graph->array[src] = node;

    
    node = newAdjListNode(src);
    node->next = graph->array[dest];
    graph->array[dest] = node;
}


void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        printf("%d:", i);
        for (struct AdjListNode* cur = graph->array[i]; cur; cur = cur->next) {
            printf(" %d", cur->dest);
        }
        printf("\n");
    }
}

int main() {
    int V = 5;
    struct Graph* graph = createGraph(V);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printf("Adjacency list representation:\n");
    printGraph(graph);

    return 0;
}