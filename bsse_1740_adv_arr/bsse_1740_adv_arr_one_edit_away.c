/*
Name        : Md.Tofazzol Alam Rahat
Roll        : BSSE-1740
Section     : B
Course      : Structured Programming Lab
Topic name  : one edit away
note        : i have taken help from google to understand the logic
*/
#include <stdio.h>
#include <string.h>

// Check if two strings of same length differ by exactly one character
int checkReplace(char s1[], char s2[]) {
    int i = 0;
    int got = 0;

    while(i < strlen(s1)) {
        if(s1[i] != s2[i]) {
            got++;
        }
        i++;
    }

    if(got == 0 || got > 1) return 0; // no difference or more than 1 difference → false
    return 1; // exactly one replacement → true
}

// Check if deleting one character from s1 makes it equal to s2
int checkDelete(char s1[], char s2[]) {
    int i = 0, j = 0;
    int got = 0;

    while(i < strlen(s1) && j < strlen(s2)) {
        if(s1[i] != s2[j]) {
            if(got > 0) return 0; // already deleted one → cannot delete again
            got++;
            i++; // skip one char in s1
            continue;
        }
        i++; j++;
    }
    return 1;
}

// Check if inserting one character into s1 makes it equal to s2
int checkInsert(char s1[], char s2[]) {
    int i = 0, j = 0;
    int got = 0;

    while(i < strlen(s1) && j < strlen(s2)) {
        if(s1[i] != s2[j]) {
            if(got > 0) return 0; // already inserted one → cannot insert again
            got++;
            j++; // skip one char in s2
            continue;
        }
        i++; j++;
    }
    return 1;
}

// Main function to decide which operation to check
int p1(char s1[], char s2[]) {
    int lenD = strlen(s1) - strlen(s2);

    if(lenD > 1 || lenD < -1) return 0;       // length difference >1 → cannot be one edit away
    if(lenD == 0) return checkReplace(s1, s2); // same length → check replacement
    if(lenD == 1) return checkDelete(s1, s2);  // s1 longer → check deletion
    if(lenD == -1) return checkInsert(s1, s2); // s2 longer → check insertion

    return 0;
}

int main() {
    
    char *examples[][2] = {
        {"pale", "ple"},
        {"pales", "pale"},
        {"pale", "bale"},
        {"pale", "bake"}
    };

    int n = 4;

    for(int k = 0; k < n; k++) {
        char *s1 = examples[k][0];
        char *s2 = examples[k][1];

        if(p1(s1, s2)) {
            printf("\"%s\" → \"%s\" : One edit away \n", s1, s2);
        } else {
            printf("\"%s\" → \"%s\" : Not one edit away \n", s1, s2);
        }
    }

    return 0;
}