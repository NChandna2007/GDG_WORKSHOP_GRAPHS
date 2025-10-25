#include <stdio.h>

#define V 5
#define INF 99999
#define MAXQ 100

void dijkstra(int graph[V][V], int src, int dist[V]) {
    int visited[V] = {0};
    int q[MAXQ];
    int front = 0, rear = 0;

    // Initialize all distances as infinity
    for (int i = 0; i < V; i++)
        dist[i] = INF;

    dist[src] = 0;
    q[rear++] = src;

    while (front < rear) {
        int u = q[front++]; // dequeue

        if (visited[u])
            continue;

        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] != 0 && !visited[v]) { // if edge exists
                int newDist = dist[u] + graph[u][v];
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    q[rear++] = v; // enqueue
                }
            }
        }
    }
}

int main() {
    // Adjacency matrix representation (0 means no edge)
    int graph[V][V] = {
        {0, 10, 0, 5, 0},
        {10, 0, 1, 2, 0},
        {0, 1, 0, 9, 4},
        {5, 2, 9, 0, 3},
        {0, 0, 4, 3, 0}
    };

    int dist[V];
    int src = 0;

    dijkstra(graph, src, dist);

    printf("Vertex\tDistance from Source %d\n", src);
    for (int i = 0; i < V; i++)
        printf("%d\t%d\n", i, dist[i]);

    return 0;
}
