/*
Name        : Md.Tofazzol Alam Rahat
Roll        : BSSE-1740
Section     : B
Course      : Structured Programming Lab
Topic name  : sum of array elements using pointer
*/
#include <stdio.h>
#include <stdlib.h>

int sumOfArray(int *arr, int size) {
    int i, sum = 0;
    for(i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", (arr + i));         
        sum += *(arr + i);              
    }
    return sum;
}

int main() {
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));  // dynamic memory allocation

    if (arr == NULL) {// check memory allocation
        printf("Memory allocation failed.\n");
        return 1;
    }

    int sum = sumOfArray(arr, n);  

    printf("Sum of array elements: %d\n", sum);

    free(arr);  
    return 0;
}