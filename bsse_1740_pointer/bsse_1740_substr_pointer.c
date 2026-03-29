/*
Name        : Md.Tofazzol Alam Rahat
Roll        : BSSE-1740
Section     : B
Course      : Structured Programming Lab
Topic name  : pointer version of String 2_Substring
*/

#include <stdio.h>
#include <stdlib.h>

// if sub is a substring of str 
int substring(char *str, char *sub) {
    while (*str) {
        char *s = str;
        char *t = sub;

        while (*s && *t && *s == *t) {
            s++;
            t++;
        }

        if (*t == '\0') return 1;  // substring found
        str++;
    }
    return 0;  // not found
}

int main() {
    char *a = (char *)malloc(20 * sizeof(char));
    char *b = (char *)malloc(20 * sizeof(char));

    if (a == NULL || b == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    //static initialization
    char *temp1 = "Rahat";
    char *temp2 = "ha";

    // Copy temp1 to a 
    char *pa = a;
    char *pt1 = temp1;
    while (*pt1) {
        *pa = *pt1;
        pa++;
        pt1++;
    }
    *pa = '\0';

    // Copy temp2 to b 
    char *pb = b;
    char *pt2 = temp2;
    while (*pt2) {
        *pb = *pt2;
        pb++;
        pt2++;
    }
    *pb = '\0';

    // Check substring
    int result = substring(a, b);

    if (result)
        printf("'%s' is a substring of '%s'\n", b, a);
    else
        printf("'%s' is not a substring of '%s'\n", b, a);

    free(a);
    free(b);
    return 0;
}