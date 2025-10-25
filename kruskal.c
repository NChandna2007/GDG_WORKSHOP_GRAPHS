#include <stdio.h>
#include <stdlib.h>

#define V 4     // number of vertices
#define E 5     // number of edges

// Comparator for sorting edges by weight
int comparator(const void* a, const void* b) {
    const int* p1 = (const int*)a;
    const int* p2 = (const int*)b;
    return p1[2] - p2[2];
}

// Initialize parent[] and rank[]
void makeSet(int parent[], int rank[]) {
    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

// Find parent (with path compression)
int findParent(int parent[], int node) {
    if (parent[node] != node)
        parent[node] = findParent(parent, parent[node]);
    return parent[node];
}

// Union two sets (by rank)
void unionSet(int u, int v, int parent[], int rank[]) {
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (u != v) {
        if (rank[u] < rank[v])
            parent[u] = v;
        else if (rank[u] > rank[v])
            parent[v] = u;
        else {
            parent[v] = u;
            rank[u]++;
        }
    }
}

// Function to find the Minimum Spanning Tree (MST)
int kruskalAlgo(int edges[E][3]) {
    // Sort edges by weight
    qsort(edges, E, sizeof(edges[0]), comparator);

    int parent[V];
    int rank[V];
    makeSet(parent, rank);

    int minCost = 0;

    printf("Edges in the Minimum Spanning Tree:\n");
    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        int parentU = findParent(parent, u);
        int parentV = findParent(parent, v);

        if (parentU != parentV) {
            printf("%d - %d : %d\n", u, v, wt);
            minCost += wt;
            unionSet(parentU, parentV, parent, rank);
        }
    }

    return minCost;
}

// Driver code
int main() {
    // Each edge: {source, destination, weight}
    int edges[E][3] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    int minCost = kruskalAlgo(edges);

    printf("\nTotal cost of Minimum Spanning Tree: %d\n", minCost);

    return 0;
}
