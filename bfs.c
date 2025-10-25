#include <stdio.h>

#define V 5
#define MAXQ 100


void bfs(int adj[V][V], int res[V], int *resSize) {
    int visited[V] = {0};
    int q[MAXQ];
    int front = 0, rear = 0;
    int src = 0;
    visited[src] = 1;
    q[rear++] = src;

    while (front < rear) {
        int curr = q[front++];
        res[(*resSize)++] = curr;

       
        for (int x = 0; x < V; x++) {
            if (adj[curr][x] && !visited[x]) {
                visited[x] = 1;
                q[rear++] = x;
            }
        }
    }
}

int main() {
    int adj[V][V] = {0};

    int edges[][2] = {{0, 1}, {0, 2}, {1, 2}, {1, 3}, {2, 4}, {3, 4}};
    int E = sizeof(edges) / sizeof(edges[0]);

    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    int res[V];
    int resSize = 0;

    bfs(adj, res, &resSize);

    for (int i = 0; i < resSize; i++)
        printf("%d ", res[i]);

    return 0;
}