/*
Name        : Md.Tofazzol Alam Rahat
Roll        : BSSE-1740
Section     : B
Course      : Structured Programming Lab
Topic name  : min max of an array using pointer
*/
#include <stdio.h>
#include <stdlib.h>


void findMinMax(int *arr, int size, int *min, int *max) {
    printf("Enter %d elements:\n", size);//prompt for input
    for (int i = 0; i < size; i++) {
        scanf("%d", (arr + i));
    }

    *min = *arr;
    *max = *arr;

    for (int i = 1; i < size; i++) {
        if (*(arr + i) < *min)
            *min = *(arr + i);
        if (*(arr + i) > *max)
            *max = *(arr + i);
    }
}

int main() {
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));//dynamic memory allocation
    if (arr == NULL) {//check memory allocation
        printf("Memory allocation failed.\n");
        return 1;
    }

    int min, max;
    findMinMax(arr, n, &min, &max);

    printf("Minimum = %d\n", min);
    printf("Maximum = %d\n", max);

    free(arr);
    return 0;
}