/*
Name        : Md.Tofazzol Alam Rahat
Roll        : BSSE-1740
Section     : B
Course      : Structured Programming Lab
Topic name  : array 2
*/
#include<stdio.h>

int main()
{  
    int arr[] = {1, 2, 3, 4, 5}; 
    int n= sizeof(arr) / sizeof(arr[0]);

    int min = arr[0];
    int max= arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] <min) {
            min = arr[i];
        }
        if(arr[i]> max) {
            max = arr[i];
        }
    }
    printf("Minimum= %d\n", min);
    printf("Maximum= %d\n", max);
    return 0;
}               

       
        
         
