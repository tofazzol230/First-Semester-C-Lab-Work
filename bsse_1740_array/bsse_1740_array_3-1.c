/*
Name        : Md.Tofazzol Alam Rahat
Roll        : BSSE-1740
Section     : B
Course      : Structured Programming Lab
Topic name  : array 3
*/
#include<stdio.h>

int main(){

int arr[]={1,2,3,4,5};
int n= sizeof(arr) / sizeof(arr[0]);

for(int i = 0; i < n/2; i++) {
    int temp = arr[i];
    arr[i] = arr[n-1-i];
    arr[n-1-i] = temp;
} 
for(int i = 0; i < n; i++){
    printf("%d ", arr[i]);
}
    printf("\n");  

return 0;
}