/*
Name        : Md.Tofazzol Alam Rahat
Roll        : BSSE-1740
Section     : B
Course      : Structured Programming Lab
Topic name  : power set of an array
*/
#include <stdio.h>
#include <math.h> // for pow()

int main() {
    int arr[] = {1, 2, 3};                // input array
    int n = sizeof(arr) / sizeof(arr[0]); // number of elements in array

    // Total number of subsets = 2^n
    int power_set_size = (int)pow(2, n);  

    printf("Power set:\n");

    // Loop over all possible subsets
    for (int i = 0; i < power_set_size; i++) {
        printf("{ ");
        // Loop over each element to check if it is included in current subset
        for (int j = 0; j < n; j++) {
            // Check j-th bit of i; if 1 → include arr[j] in subset
            if (i & (1 << j)) {   // still using bitmask for subset generation
                printf("%d ", arr[j]);
            }
        }
        printf("}\n");
    }

    return 0;
}