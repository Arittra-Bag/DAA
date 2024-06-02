#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 99999
#define MAX 100

void printSolution(int dist[][MAX], int V);

/* A utility function to find the minimum of two integers */
int min(int a, int b) {
    return (a < b) ? a : b;
}

/* The Floyd-Warshall algorithm */
void floydWarshall(int graph[][MAX], int V) {
    int dist[MAX][MAX];

    /* Initialize the solution matrix same as input graph matrix */
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    /* Add all vertices one by one to the set of intermediate vertices. */
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    /* Print the shortest distance matrix */
    printSolution(dist, V);
}

/* A utility function to print the solution */
void printSolution(int dist[][MAX], int V) {
    printf("The following matrix shows the shortest distances between every pair of vertices:\n");
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
    int V;
    char input[10];
    int graph[MAX][MAX];

    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    printf("Enter the adjacency matrix (use 'inf' for infinity):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%s", input);
            if (strcmp(input, "inf") == 0)
                graph[i][j] = INF;
            else
                graph[i][j] = atoi(input);
        }
    }

    floydWarshall(graph, V);

    return 0;
}

