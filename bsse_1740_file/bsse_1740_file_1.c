/*
Name        : Md.Tofazzol Alam Rahat
Roll        : BSSE-1740
Section     : B
Course      : Structured Programming Lab
*/
#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp = fopen("students.txt", "r");
    if (!fp) { printf("Error opening students file.\n"); return 1; }

    char line[200], sid[10], name[50], dept[10], cid[10], searchID[10];
    float cgpa;
    int found = 0;

    printf("Enter Student ID to search: ");
    scanf("%s", searchID);

    fgets(line, sizeof(line), fp); // skip header
    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%[^,],%[^,],%[^,],%[^,],%f", sid, name, dept, cid, &cgpa);
        if (strcmp(sid, searchID) == 0) {
            printf("\nStudent Found:\n");
            printf("ID: %s\nName: %s\nDept: %s\nCourse ID: %s\nCGPA: %.2f\n",
                   sid, name, dept, cid, cgpa);
            found = 1;
            break;
        }
    }
    if (!found) printf("Student with ID %s not found.\n", searchID);

    fclose(fp);
    return 0;
}