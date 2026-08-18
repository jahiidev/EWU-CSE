//Name: Md. Jahidul Islam
//ID: 2026-2-60-209

#include <stdio.h>

struct stdData {
    int stdID;
    char stdName[50];
    float gpaCSE_103, gpaMAT_101, gpaENG_7101;
    float cgpa;
};

int main() {
    FILE *inFile, *outFile;
    inFile = fopen("student_input.txt", "r");
    outFile = fopen("output.txt", "w");

    struct stdData stdList[100];
    int n, i;
    fscanf(inFile, "%d", &n);

    for (i = 0; i < n; i++) {
        fscanf(inFile, "%d", &stdList[i].stdID);
        fscanf(inFile, "%s", stdList[i].stdName);
        fscanf(inFile, "%f", &stdList[i].gpaCSE_103);
        fscanf(inFile, "%f", &stdList[i].gpaMAT_101);
        fscanf(inFile, "%f", &stdList[i].gpaENG_7101);

        stdList[i].cgpa = (stdList[i].gpaCSE_103 * 4.5 + stdList[i].gpaMAT_101 * 3.0 + stdList[i].gpaENG_7101 * 3.0) / (4.5 + 3.0 + 3.0);
    }

    fprintf(outFile, "----------------------------------------------------------\n");
    fprintf(outFile, "%-10s %-20s %-6s %-6s %-6s %-4s\n", "ID", "Name", "CSE103", "MAT101", "ENG101", "CGPA");
    fprintf(outFile, "----------------------------------------------------------\n");
    for (i = 0; i < n; i++) {
        fprintf(outFile, "%-10d %-20s %-6.2f %-6.2f %-6.2f %-4.2f\n", stdList[i].stdID, stdList[i].stdName, stdList[i].gpaCSE_103, stdList[i].gpaMAT_101, stdList[i].gpaENG_7101, stdList[i].cgpa);
    }
    fprintf(outFile, "----------------------------------------------------------\n");

    fclose(inFile);
    fclose(outFile);

    return 0;
}
