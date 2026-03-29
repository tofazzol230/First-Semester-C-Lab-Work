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

    char cline[200], checked[1000] = "";
    fgets(cline, sizeof(cline), cfp); // skip header

    printf("%-25s %-10s\n", "Instructor", "Avg CGPA");
    printf("------------------------------------------\n");

    while (fgets(cline, sizeof(cline), cfp)) {
        char cid[10], cname[50], teacher[50];
        int credit;
        sscanf(cline, "%[^,],%[^,],%d,%[^\n]", cid, cname, &credit, teacher);

        if (strstr(checked, teacher)) continue; // already processed
        strcat(checked, teacher);
        strcat(checked, "|");

        FILE *cfp2 = fopen("courses.txt", "r");
        fgets(cline, sizeof(cline), cfp2);

        float sum = 0; int count = 0;
        while (fgets(cline, sizeof(cline), cfp2)) {
            char cid2[10], cname2[50], teacher2[50];
            int credit2;
            sscanf(cline, "%[^,],%[^,],%d,%[^\n]", cid2, cname2, &credit2, teacher2);
            if (strcmp(teacher, teacher2) == 0) {
                FILE *sfp = fopen("students.txt", "r");
                char sline[200];
                fgets(sline, sizeof(sline), sfp);

                while (fgets(sline, sizeof(sline), sfp)) {
                    char sid[10], name[50], dept[10], scid[10];
                    float cgpa;
                    sscanf(sline, "%[^,],%[^,],%[^,],%[^,],%f", sid, name, dept, scid, &cgpa);
                    if (strcmp(scid, cid2) == 0) {
                        sum += cgpa;
                        count++;
                    }
                }
                fclose(sfp);
            }
        }
        fclose(cfp2);

        if (count > 0)
            printf("%-25s %-10.2f\n", teacher, sum / count);
    }

    fclose(cfp);
    return 0;
}