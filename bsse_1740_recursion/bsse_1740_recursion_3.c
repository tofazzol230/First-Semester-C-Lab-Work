/*
Name        : Md.Tofazzol Alam Rahat
Roll        : BSSE-1740
Section     : B
Course      : Structured Programming Lab
Topic name  : Recursion 3_Reverse an array
*/
#include <stdio.h>

void reverse(int arr[], int n);

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    reverse(arr, n);

    printf("Reversed array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

void reverse(int arr[], int n) {
    
    if (n <= 1) {
        return; 
    }   
    
    int temp = arr[0];
    arr[0] = arr[n - 1];
    arr[n - 1] = temp;      
    
    reverse(arr + 1, n - 2);    
}