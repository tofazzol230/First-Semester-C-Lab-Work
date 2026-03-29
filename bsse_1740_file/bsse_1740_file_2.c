/*
Name        : Md.Tofazzol Alam Rahat
Roll        : BSSE-1740
Section     : B
Course      : Structured Programming Lab
*/
#include <stdio.h>
#include <string.h>

int main() {
    FILE *sfp = fopen("students.txt", "r");
    FILE *cfp;
    if (!sfp) { printf("Error opening students file.\n"); return 1; }

    char sline[200], cline[200];
    fgets(sline, sizeof(sline), sfp); // skip student header

    printf("%-5s %-15s %-6s %-8s %-25s %-5s %-20s\n",
           "ID", "Name", "Dept", "C_ID", "Course Name", "Cred", "Teacher");
    printf("-------------------------------------------------------------------------------\n");

    while (fgets(sline, sizeof(sline), sfp)) {
        char sid[10], name[50], dept[10], cid[10];
        float cgpa;
        sscanf(sline, "%[^,],%[^,],%[^,],%[^,],%f", sid, name, dept, cid, &cgpa);

        cfp = fopen("courses.txt", "r");
        fgets(cline, sizeof(cline), cfp); // skip header

        while (fgets(cline, sizeof(cline), cfp)) {
            char course_id[10], cname[50], teacher[50];
            int credit;
            sscanf(cline, "%[^,],%[^,],%d,%[^\n]", course_id, cname, &credit, teacher);
            if (strcmp(cid, course_id) == 0) {
                printf("%-5s %-15s %-6s %-8s %-25s %-5d %-20s\n",
                       sid, name, dept, cid, cname, credit, teacher);
                break;
            }
        }
        fclose(cfp);
    }

    fclose(sfp);
    return 0;
}