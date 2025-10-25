#include <stdio.h>
#include <limits.h>

#define V 5
#define INF 99999  // Representing infinity

void floydWarshall(int graph[V][V]) {
    int dist[V][V];

    // Step 1: Initialize distance matrix same as graph
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Step 2: Update distances using intermediate vertices
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Step 3: Print final shortest distance matrix
    printf("Shortest distances between every pair of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[V][V] = {
        {0, 3, INF, 7, INF},
        {8, 0, 2, INF, INF},
        {5, INF, 0, 1, INF},
        {2, INF, INF, 0, 1},
        {INF, INF, INF, INF, 0}
    };

    floydWarshall(graph);

    return 0;
}
