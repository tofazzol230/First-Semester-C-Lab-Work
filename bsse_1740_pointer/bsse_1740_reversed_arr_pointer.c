/*
Name        : Md.Tofazzol Alam Rahat
Roll        : BSSE-1740
Section     : B
Course      : Structured Programming Lab
Topic name  : reverse array using pointer
*/

#include <stdio.h>
#include <stdlib.h>

//reverse array using pointer only
void reverseArray(int *arr, int size) {
    int *start = arr;
    int *end = arr + size - 1;

    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

void printArray(int *arr, int size) {//print array using pointer only
    for (int i = 0; i < size; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));//dynamic memory allocation
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", (arr + i));
    }

    reverseArray(arr, n);
    printf("Reversed array: ");
    printArray(arr, n);

    free(arr);
    return 0;
}