/*
Name        : Md.Tofazzol Alam Rahat
Roll        : BSSE-1740
Section     : B
Course      : Structured Programming Lab
Topic name  : merge two sorted arrays using pointer
*/

#include <stdio.h>
#include <stdlib.h>

//merge two sorted arrays using pointer only
void mergeArrays(int *a1, int n1, int *a2, int n2, int *a3) {
    int i = 0, j = 0, k = 0;

    while (i < n1 + n2) {
        if (j < n1 && (k >= n2 || *(a1 + j) < *(a2 + k))) {
            *(a3 + i) = *(a1 + j);
            j++;
        }
        else if (k < n2 && (j >= n1 || *(a1 + j) > *(a2 + k))) {
            *(a3 + i) = *(a2 + k);
            k++;
        }
        else if (j < n1 && k < n2 && *(a1 + j) == *(a2 + k)) {
            *(a3 + i) = *(a1 + j);
            i++;
            *(a3 + i) = *(a2 + k);
            j++;
            k++;
        }
        i++;
    }
}

// print array using pointer
void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

int main() {
    int n1, n2;

    printf("Enter size of first sorted array: ");
    scanf("%d", &n1);
    int *a1 = (int *)malloc(n1 * sizeof(int));
    if (a1 == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d elements of first sorted array:\n", n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", (a1 + i));
    }

    printf("Enter size of second sorted array: ");
    scanf("%d", &n2);
    int *a2 = (int *)malloc(n2 * sizeof(int));
    if (a2 == NULL) {
        printf("Memory allocation failed.\n");
        free(a1);
        return 1;
    }

    printf("Enter %d elements of second sorted array:\n", n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", (a2 + i));
    }

    int *a3 = (int *)malloc((n1 + n2) * sizeof(int));
    if (a3 == NULL) {
        printf("Memory allocation failed.\n");
        free(a1);
        free(a2);
        return 1;
    }

    mergeArrays(a1, n1, a2, n2, a3);

    printf("Merged sorted array:\n");
    printArray(a3, n1 + n2);

    free(a1);
    free(a2);
    free(a3);
    return 0;
}