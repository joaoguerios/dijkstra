#include <stdio.h>
#include <limits.h>

#define MAX 5
#define INF INT_MAX

int minDist(int dist[], int visited[]) {
    int min = INF, minIndex,v;

    for ( v = 0; v < MAX; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void printPath(int parent[], int j) {
    if (parent[j] == -1) {
        return;
    }
    printPath(parent, parent[j]);
    printf("%c ", 'A' + j);
}

void dijkstra(int graph[MAX][MAX], int src) {
    int dist[MAX];
    int visited[MAX] = {0};
    int parent[MAX];
    int i,count,v;

    for ( i = 0; i < MAX; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }

    dist[src] = 0;

    for ( count = 0; count < MAX - 1; count++) {
        int u = minDist(dist, visited);
        visited[u] = 1;

        for ( v = 0; v < MAX; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Cidade  Distancia   Caminho  Todas as cidades partindo de A\n");
    for ( i = 0; i < MAX; i++) {
            printf("A -> %c    %2d       A ", 'A' + i, dist[i]);
            printPath(parent, i);
            printf("\n");
    }
    printf("\n");
    printf("\n");
    printf("Cidade  Distancia   Caminho\n");
    for ( i = 0; i < MAX; i++) {
        if(i == 3 || i == 4){
            printf("A -> %c    %2d       A ", 'A' + i, dist[i]);
            printPath(parent, i);
            printf("\n");
        }
    }
}

int main() {
    int graph[MAX][MAX] = {
        {0, 4, 2, 7, 0},
        {4, 0, 1, 0, 1},
        {2, 1, 0, 3, 3},
        {7, 0, 3, 0, 2},
        {0, 1, 3, 2, 0}
    };

    dijkstra(graph, 0);

    return 0;
}

