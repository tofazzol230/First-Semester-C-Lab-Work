/*
Name        : Md.Tofazzol Alam Rahat
Roll        : BSSE-1740
Section     : B
Course      : Structured Programming Lab
Topic name  : Implementation of string functions using pointer
*/

#include <stdio.h>
#include <stdlib.h>

// calculate string length using pointer
int _strlen(char *x) {
    int len = 0;
    while (*(x + len)) {
        len++;
    }
    return len;
}

// compare two strings using pointer
int _strcmp(char *x, char *y) {
    while (*x && *y) {
        if (*x != *y)
            return *x - *y;
        x++;
        y++;
    }
    return *x - *y;
}

//copy string y into x using pointer
void _strcpy(char *x, char *y) {
    while (*y) {
        *x = *y;
        x++;
        y++;
    }
    *x = '\0';
}

int main() {
    char *a = (char *)malloc(20 * sizeof(char));
    char *b = (char *)malloc(20 * sizeof(char));

    if (a == NULL || b == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // static initialization of strings
    char *temp1 = "apple";
    char *temp2 = "banana";

    char *pa = a;
    char *pt1 = temp1;
    while (*pt1) {
        *pa = *pt1;
        pa++;
        pt1++;
    }
    *pa = '\0';

    char *pb = b;
    char *pt2 = temp2;
    while (*pt2) {
        *pb = *pt2;
        pb++;
        pt2++;
    }
    *pb = '\0';

    printf("String a: %s\n", a);
    printf("String b: %s\n", b);

    int cmp = _strcmp(a, b);
    if (cmp < 0)
        printf("a is less than b\n");
    else if (cmp > 0)
        printf("a is greater than b\n");
    else
        printf("a is equal to b\n");

    printf("Length of a: %d\n", _strlen(a));
    printf("Length of b: %d\n", _strlen(b));

    printf("Before copying, a = %s\n", a);
    _strcpy(a, b);
    printf("After copying, a = %s\n", a);

    free(a);
    free(b);
    return 0;
}