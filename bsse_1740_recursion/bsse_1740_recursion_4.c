
/*Name      : Md.Tofazzol Alam Rahat
Roll        : BSSE-1740
Section     : B
Course      : Structured Programming Lab    
Topic name  : Recursion 4_Merge sort 
*/

#include <stdio.h>

void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    mergeSort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        
        merge(arr, left, mid, right);
    }
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    
    int L[100], R[100]; 
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}