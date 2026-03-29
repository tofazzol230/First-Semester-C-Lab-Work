/*
Name        : Md. Tofazzol Alam Rahat
Roll        : BSSE-1740
Section     : B
Course      : Structured Programming Lab
Topic name  : adjacency matrix representation of a graph using pointer and malloc
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    printf("Enter number of nodes and edges:\n");
    scanf("%d%d", &n, &m);

    int **matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        *(matrix + i) = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            *(*(matrix + i) + j) = 0;
        }
    }

    printf("Enter nodes and weight for each edge:\n");
    for (int i = 0; i < m; i++) {
        int a, b, d;
        printf("Edge %d\n", i + 1);
        scanf("%d%d%d", &a, &b, &d);
        printf("Edge from %d to %d with weight %d\n", a, b, d);
        *(*(matrix + a) + b) = d;
    }

    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", *(*(matrix + i) + j));
        }
        printf("\n");
    }

    int x, y;
    printf("\nEnter nodes to find weight:\n");
    scanf("%d%d", &x, &y);
    if (*(*(matrix + x) + y)) {
        printf("Weight is %d\n", *(*(matrix + x) + y));
    } else {
        printf("No edge\n");
    }

    for (int i = 0; i < n; i++) {
        free(*(matrix + i));
    }
    free(matrix);

    return 0;
}