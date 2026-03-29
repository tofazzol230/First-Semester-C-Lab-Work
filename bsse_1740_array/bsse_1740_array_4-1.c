/*
Name        : Md.Tofazzol Alam Rahat
Roll        : BSSE-1740
Section     : B
Course      : Structured Programming Lab
Topic name  : array 4
*/
#include <stdio.h>

int main() {
    int arr1[] = {1,3,5,7,9,11,13,15,17,19};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[] = {1,2,3,4,5,6,7,8};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    int arr3[n1 + n2];
    int i = 0, j = 0;

    for (int k = 0; k < n1 + n2; k++) {
        if (i < n1 && (j >= n2 || arr1[i] < arr2[j])) {
            arr3[k] = arr1[i++];
        }
        else if (j < n2 && (i >= n1 || arr1[i] > arr2[j])) {
            arr3[k] = arr2[j++];
        }
        else if (i < n1 && j < n2 && arr1[i] == arr2[j]) {
            arr3[k++] = arr1[i];
            arr3[k] = arr2[j];
            i++;
            j++;
        }
    }

    
    for (int x = 0; x < n1 + n2; x++) {
        printf("%d ", arr3[x]);
    }
    printf("\n");

    return 0;
}