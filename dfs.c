#include <stdio.h>

#define V 5
#define MAXS 100

void dfs(int adj[V][V], int res[V], int *resSize) {
    int visited[V] = {0};
    int stack[MAXS];
    int top = -1;
    int src = 0;

    stack[++top] = src;

    while (top >= 0) {
        int curr = stack[top--];

        if (!visited[curr]) {
            visited[curr] = 1;
            res[(*resSize)++] = curr;

           
            for (int x = V - 1; x >= 0; x--) {
                if (adj[curr][x] && !visited[x]) {
                    stack[++top] = x;
                }
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

    dfs(adj, res, &resSize);

    for (int i = 0; i < resSize; i++)
        printf("%d ", res[i]);

    return 0;
}
