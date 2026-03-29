
/*
Name        : Md.Tofazzol Alam Rahat
Roll        : BSSE-1740
Section     : B
Course      : Structured Programming Lab
Topic name  : Patterns

Note        : I’ve separated all the pattern structures into individual
                functions and used a switch-case menu to let the user choose which pattern 
                to display This makes the program modular, readable, and easy to maintain.
*/

#include <stdio.h>
// Global variable to store user input
int n;

// Function declarations
void abc();               // Alphabet triangle
void star_pyramid();      // Star pyramid
void hour_glass();          // Hour glass (reverse and normal star pyramid)
void dimond();            // Hollow diamond
void pascaltriangle();    // Pascal's triangle

int main() {
    int choice;

    // Menu loop
    do {
        // Display menu options
        printf("\nChoose a pattern to display:\n");
        printf("1. Alphabet Triangle\n");
        printf("2. Star Pyramid\n");
        printf("3. Hour Glass\n");
        printf("4. Hollow Diamond\n");
        printf("5. Pascal's Triangle\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Switch based on user choice
        switch (choice) {
            case 1:
                abc();
                break;
            case 2:
                star_pyramid();
                break;
            case 3:
               hour_glass();
                break;
            case 4:
                dimond();
                break;
            case 5:
                pascaltriangle();
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

// Function to print alphabet triangle
void abc() {
    printf("\nAlphabet Triangle:\n");
    printf("Enter a number: ");
    scanf("%d", &n);

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            printf(" %c", 'A' + j);
        }
        printf("\n");
    }
}

// Function to print star pyramid
void star_pyramid() {
    printf("\nStar Pyramid:\n");
    printf("Enter a number: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            printf(" ");
        }
        for (int j = 0; j <= i; j++) {
            printf(" *");
        }
        printf("\n");
    }
}

// Function to print hour glass (reverse and normal star pyramid)
void hour_glass()
 {
    printf("\nHour Glass:\n");
    printf("Enter a number: ");
    scanf("%d", &n);

    // Reverse pyramid
    for (int i = n; i >=1; i--) {
        for (int j = 0; j < n - i; j++) {
            printf(" ");
        }
        for (int j = 0; j <= i; j++) {
            printf(" *");
        }
        printf("\n");
    }

    // Normal pyramid
    for (int i = 0; i <=n; i++) {
        for (int j = 0; j < n - i; j++) {
            printf(" ");
        }
        for (int j = 0; j <= i; j++) {
            printf(" *");
        }
        printf("\n");
    }
}

// Function to print hollow diamond
void dimond() {
    printf("\nHollow Diamond:\n");
    printf("Enter a number: ");
    scanf("%d", &n);

    // Upper half
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            printf(" ");
        }
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i)
                printf(" *");
            else
                printf("  ");
        }
        printf("\n");
    }

    // Lower half
    for (int i = n; i >= 0; i--) {
        for (int j = 0; j < n - i; j++) {
            printf(" ");
        }
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i)
                printf(" *");
            else
                printf("  ");
        }
        printf("\n");
    }
}

// Function to print Pascal's triangle
void pascaltriangle() {
    printf("\nPascal's Triangle:\n");
    printf("Enter a number: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            printf("  ");
        }

        int value = 1;
        for (int j = 0; j <= i; j++) {
            printf("%4d ", value);  //I learned the "%4d" format from online. It prints numbers with a width of 4 characters for better alignment.
            value = value * (i - j) / (j + 1);
        }
        printf("\n");
    }
}