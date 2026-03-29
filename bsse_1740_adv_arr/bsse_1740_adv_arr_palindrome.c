/*
Name        : Md.Tofazzol Alam Rahat
Roll        : BSSE-1740
Section     : B
Course      : Structured Programming Lab
Topic name  : palindrome pairs in an array of strings
note        : i have taken help from google to understand the logic,and to uderstand array of strings
*/
#include <stdio.h>
#include <string.h>
int forms_palindrome(char *a, char *b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    int total_len = len_a + len_b;

    for (int i = 0; i < total_len / 2; i++) {
        char left, right;

        if (i < len_a)// character from left
            left = a[i];
        else
            left = b[i - len_a];//character from second string

        // character from right
        if (i < len_b)
            right = b[len_b - 1 - i];
        else
            right = a[len_a - 1 - (i - len_b)];

        if (left != right)
            return 0; // not palindrome
    }
    return 1; // forms palindrome
}

int main() {
    char *words[] = {"bat", "tab", "cat", "at", "ta", "abc", "cba"};
    int n = sizeof(words) / sizeof(words[0]);

    printf("Word pairs forming palindromes:\n");
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (forms_palindrome(words[i], words[j])) {
                printf("%s %s\n", words[i], words[j]);
            }
        }
    }

    return 0;
}