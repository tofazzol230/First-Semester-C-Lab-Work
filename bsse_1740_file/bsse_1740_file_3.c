/*
Name        : Md.Tofazzol Alam Rahat
Roll        : BSSE-1740
Section     : B
Course      : Structured Programming Lab
*/
#include <stdio.h>
#include <string.h>

int main() {
    FILE *cfp = fopen("courses.txt", "r");
    if (!cfp) { printf("Error opening courses file.\n"); return 1; }

    char cline[200];
    fgets(cline, sizeof(cline), cfp); // skip header

    printf("%-10s %-25s %-20s %-10s\n", "CourseID", "CourseName", "Top Student", "CGPA");
    printf("---------------------------------------------------------------\n");

    while (fgets(cline, sizeof(cline), cfp)) {
        char cid[10], cname[50], teacher[50];
        int credit;
        sscanf(cline, "%[^,],%[^,],%d,%[^\n]", cid, cname, &credit, teacher);

        FILE *sfp = fopen("students.txt", "r");
        if (!sfp) { printf("Error opening students file.\n"); return 1; }

        char sline[200], sid[10], name[50], dept[10], scid[10];
        float cgpa, top = -1;
        char topname[50] = "";

        fgets(sline, sizeof(sline), sfp); // skip header
        while (fgets(sline, sizeof(sline), sfp)) {
            sscanf(sline, "%[^,],%[^,],%[^,],%[^,],%f", sid, name, dept, scid, &cgpa);
            if (strcmp(scid, cid) == 0 && cgpa > top) {
                top = cgpa;
                strcpy(topname, name);
            }
        }
        fclose(sfp);

        if (top >= 0)
            printf("%-10s %-25s %-20s %-10.2f\n", cid, cname, topname, top);
    }
    fclose(cfp);
    return 0;
}