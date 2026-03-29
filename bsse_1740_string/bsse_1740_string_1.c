/*
Name        : Md.Tofazzol Alam Rahat
Roll        : BSSE-1740
Section     : B
Course      : Structured Programming Lab
Topic name  : Srting 1_Copy, Compare, Length
*/
#include<stdio.h>

void _strcpy(char x[],char y[]);
int _strcmp(char x[], char y[]);
int _strlen(char x[]);

int main() {
    char a[]="apple";
    char b[] = "banana";
    printf("String a: %s\n", a);
    printf("String b: %s\n", b);
    
    int cmp = _strcmp(a, b);
    if (cmp < 0) {
        printf("a is less than b\n");
    } else if (cmp > 0) {
        printf("a is greater than b\n");
    } else {
        printf("a is equal to b\n");
    }

    int len= _strlen(a);
    printf("Length of a: %d\n", len);
    int len2 = _strlen(b);
    printf("Length of b: %d\n", len2);

    printf("Before copying, a = %s\n",a);
    _strcpy(a,b);
    printf("After copying, a = %s\n", a);

    return 0;
}

void _strcpy(char x[], char y[]){
    int i = 0;
    while (y[i]) {//if y[i] is null it will stop
        x[i] = y[i];//copying character by character
        i++;
    }
    x[i] = '\0'; //adding null character at the end
    
}


int _strcmp(char x[], char y[]){
    int i = 0;
    while (x[i] && y[i]) {//if x[i] or y[i] is null it will stop
        if (x[i] != y[i]) {
            return x[i] - y[i]; //returning difference of first unmatched characters
        }
        i++;
    }
    return x[i] - y[i]; //if one string is a prefix of the other
    
}

int _strlen(char x[]){
    int i = 0;
    while (x[i]) {//if x[i] is null it will stop
        i++;//counting character by character until null character
    }
    return i; //returning length without counting null character
}