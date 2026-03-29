/*
Name        : Md. Tofazzol Alam Rahat
Roll        : BSSE-1740
Section     : B
Course      : Structured Programming Lab
Topic name  : Sort multiple strings using pointer and malloc
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    printf("Enter number of strings:\n");
    scanf("%d", &n);
    getchar(); 

    char **list = (char **)malloc(n * sizeof(char *)); 
    int size = 100;

    for (int i = 0; i < n; i++) {
        *(list + i) = (char *)malloc(size * sizeof(char));
        printf("Enter string %d:\n", i + 1);
        fgets(*(list + i), size, stdin);
        (*(list + i))[strcspn(*(list + i), "\n")] = '\0'; 
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(*(list + i), *(list + j)) > 0) {
                char *temp = *(list + i);
                *(list + i) = *(list + j);
                *(list + j) = temp;
            }
        }
    }

    printf("\nSorted Strings:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", *(list + i));
        free(*(list + i));
    }

    free(list); 
    return 0;
}