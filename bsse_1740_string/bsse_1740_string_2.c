/*
Name        : Md.Tofazzol Alam Rahat
Roll        : BSSE-1740
Section     : B
Course      : Structured Programming Lab
Topic name  : Srting 2_Substring
*/
#include <stdio.h>
int substring(char str[], char sub[]);

int main() {
    char a[] = "Rahat";
    char b[] = "ha";
    
    int result = substring(a, b);//  a=main string ---- b=substring
        if (result) {
        printf("'%s' is a substring of '%s'\n", b, a);
        } 
        else 
        printf("'%s' is not a substring of '%s'\n", b, a);
         
    return 0;
}

int substring(char str[], char sub[]) {
    int i, j;
    for (i = 0; str[i]; i++) {
        for (j = 0; sub[j] && str[i + j] == sub[j]; j++);//if sub[j] is null it will stop
        if (!sub[j] ) {
            return 1; // Found the substring
        }
    }
    return 0; // Substring not found
}