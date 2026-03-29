/*
Name        : Md.Tofazzol Alam Rahat
Roll        : BSSE-1740
Section     : B
Course      : Structured Programming Lab
Topic name  : swap two numbers using pointer
*/
#include<stdio.h>
void swap(int *a,int *b) {
    int temp;
    temp= *a;  
    *a =*b;  
    *b= temp;
}
int main() {
    int x=5, y=10;
    printf("Before swap: x=%d, y=%d\n",x,y);
    swap(&x, &y);
    printf("After swap: x=%d, y=%d\n",x,y);
    return 0;
}   