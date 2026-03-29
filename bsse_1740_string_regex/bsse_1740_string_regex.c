/*
Name        : Md.Tofazzol Alam Rahat
Roll        : BSSE-1740
Section     : B
Course      : Structured Programming Lab
Topic name  : Regular Expression Matching
NOTE:Comments and idea are from online sources like leetcode.
*/
#include <stdio.h>

int boolisMatch(const char *text, const char *pattern) {
    if (*pattern == '\0') {// base case when pattern is over text should also be over
        return *text == '\0';
    }
    int initialcase = (*text != '\0') && (*text == *pattern || *pattern == '.');//if text is not over and character matches or pattern has '.'

    if (*(pattern + 1) == '*') {//if next character of pattern is '*' then two cases arise
        return (boolisMatch(text, pattern + 2) ||(initialcase && boolisMatch(text + 1, pattern)));
        //case 1: '*' represents zero occurrence of preceding character 
        // case 2: '*' represents one or more occurrence of preceding character
    } else {//if next character of pattern is not '*' then move to next character of both text and pattern
        return initialcase && boolisMatch(text + 1, pattern + 1);
    }
}

int main() {
    char text[100], pattern[100];

    printf("Enter text: ");
    scanf("%s", text);

    printf("Enter pattern: ");
    scanf("%s", pattern);

    if (boolisMatch(text, pattern))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}