/*
Name        : Md.Tofazzol Alam Rahat
Roll        : BSSE-1740
Section     : B
Course      : Structured Programming Lab
Topic name  : array 1
*/
#include<stdio.h>

int main(){ 
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);
    int arr[n];
        
    for(int i = 0; i < n; i++) {
        scanf(" %d", &arr[i]); 
        
    }
    int sum = 0;
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]); 
        sum += arr[i]; 
    }
    printf("\n");
    printf("Sum of array elements: %d\n", sum);
return 0;
}
