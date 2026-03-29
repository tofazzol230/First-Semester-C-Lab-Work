/*
Name        : Md.Tofazzol Alam Rahat
Roll        : BSSE-1740
Section     : B
Course      : Structured Programming Lab
Topic name  : Recursion 2_Find maximum in an array
*/
#include <stdio.h>

int max(int arr[], int n);

int main() {
    int arr[] = {1, 2, 6, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int Max = max(arr, n);
    printf("Max = %d\n", Max);
    return 0;
}

int max(int arr[], int n) {
    if (n == 1) {
        return arr[0];
    }

    int temp = max(arr, n - 1);

    if (arr[n - 1] > temp) {
        return arr[n - 1];
    } else {
        return temp;
    }
}