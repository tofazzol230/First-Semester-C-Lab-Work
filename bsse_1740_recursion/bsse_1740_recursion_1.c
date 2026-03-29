/*
Name        : Md.Tofazzol Alam Rahat
Roll        : BSSE-1740
Section     : B
Course      : Structured Programming Lab
Topic name  : Recursion 1_Sum of array elements
*/
#include<stdio.h>

int sumarr(int arr[],int n);
 int main(){

    int arr[]={1,2,3,4,5};
    int n =sizeof(arr)/sizeof(arr[0]);
    int sum= sumarr(arr, n);
    printf("%d",sum);
    return 0;
 }
    int sumarr(int arr[],int n){
        if (n<=0)
            return 0;
        return arr[n-1]+sumarr(arr,n-1);
    }   

