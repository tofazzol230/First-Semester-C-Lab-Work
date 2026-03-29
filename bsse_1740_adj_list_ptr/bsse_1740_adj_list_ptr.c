/*
Name        : Md. Tofazzol Alam Rahat
Roll        : BSSE-1740
Section     : B
Course      : Structured Programming Lab
Topic name  : Adjacency list representation of a graph using malloc and pointer arithmeti
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_EDGES 100

int main() {
    int n, m;
    printf("Enter number of nodes and edges:\n");
    scanf("%d%d", &n, &m);

    int **to = (int **)malloc(n * sizeof(int *));
    int **weight = (int **)malloc(n * sizeof(int *));
    int *count = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        *(count + i) = 0;
        *(to + i) = (int *)malloc(MAX_EDGES * sizeof(int));
        *(weight + i) = (int *)malloc(MAX_EDGES * sizeof(int));
    }

    printf("Enter edges (from to weight):\n");
    for (int i = 0; i < m; i++) {
        int a, b, w;
        printf("Edge %d: ", i + 1);
        scanf("%d%d%d", &a, &b, &w);

        int pos = *(count + a);
        *(*(to + a) + pos) = b;
        *(*(weight + a) + pos) = w;
        *(count + a) += 1;
    }

    printf("\nAdjacency List Representation:\n");
    for (int i = 0; i < n; i++) {
        printf("Node %d:", i);
        for (int j = 0; j < *(count + i); j++) {
            int b = *(*(to + i) + j);
            int w = *(*(weight + i) + j);
            printf(" %d(weight %d)", b, w);
        }
        printf("\n");
    }

    int x, y;
    printf("\nEnter two nodes to check connection (from to): ");
    scanf("%d%d", &x, &y);

    int found = 0;
    for (int i = 0; i < *(count + x); i++) {
        if (*(*(to + x) + i) == y) {
            printf("Connected with weight %d\n", *(*(weight + x) + i));
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("No edge found\n");
    }
    
    for (int i = 0; i < n; i++) {
        free(*(to + i));
        free(*(weight + i));
    }
    free(to);
    free(weight);
    free(count);

    return 0;
}