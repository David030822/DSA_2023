//
// Created by David on 2023. 02. 27..
//
#include "../headers/student.h"

void readStudentDetails(Student_t *pStudent, const char *input)
{
    FILE *fin = fopen(input, "r");
    if (!fin)
        exit(-500);
    fscanf(fin, "%[^\n]\n", pStudent -> name);
    fscanf(fin, "%s\n", pStudent -> neptuneCode);
    fscanf(fin, "%s\n", pStudent-> birthPlace);
    fscanf(fin, "%d %d %d", &pStudent -> dateOfBirth.year, &pStudent -> dateOfBirth.month, &pStudent -> dateOfBirth.day);
    fscanf(fin, "%ud", &pStudent -> gender);
    fscanf(fin, "%lf", &pStudent -> examResult);
}

void printStudent(Student_t student)
{
    printf("%s\n", student.name);
    printf("%s\n", student.neptuneCode);
    printf("%s\n", student.birthPlace);
    printf("%d. %d. %d.\n", student.dateOfBirth.year, student.dateOfBirth.month, student.dateOfBirth.day);
    if(student.gender == 0)
    {
        printf("Male\n");
    }
    else
    {
        printf("Female\n");
    }
    printf("%lf\n", student.examResult);
}

void allocateMemoryForStudents(Student_t **dpStudents, int numberOfStudents)
{
    *dpStudents = (Student_t *) calloc(numberOfStudents, sizeof (Student_t));
    if(!(*dpStudents))
    {
        printf("Error allocating memory!\n");
        exit(-1);
    }
}

void readAllStudentsDetails(Student_t **dpStudents,  const char *input)
{
    int numberOfStudents;
    FILE *fin = fopen(input, "r");
    if (!fin)
        exit(-500);
    fscanf(fin, "%d\n", &numberOfStudents);
    printf("The number of students is: %d\n", numberOfStudents);
    allocateMemoryForStudents(dpStudents, numberOfStudents);
    for (int i = 0; i < numberOfStudents; ++i)
    {
        fscanf(fin, "%[^\n]\n", (*dpStudents[i]).name);
        fscanf(fin, "%s\n", (*dpStudents[i]).neptuneCode);
        fscanf(fin, "%s\n", (*dpStudents[i]).birthPlace);
        fscanf(fin, "%d %d %d", &(*dpStudents[i]).dateOfBirth.year, &(*dpStudents[i]).dateOfBirth.month, &(*dpStudents[i]).dateOfBirth.day);
        fscanf(fin, "%d", &(*dpStudents[i]).gender);
        fscanf(fin, "%lf\n", &(*dpStudents[i]).examResult);
    }
}

void printAllStudents(Student_t *pStudents, int numberOfStudents, const char *destination)
{
    FILE *fout = fopen(destination, "w");
    for (int i = 0; i < numberOfStudents; ++i)
    {
        fprintf(fout, "%s\n", pStudents[i].name);
        fprintf(fout, "%s\n", pStudents[i].neptuneCode);
        fprintf(fout, "%s\n", pStudents[i].birthPlace);
        fprintf(fout, "%d. %d. %d.\n", pStudents[i].dateOfBirth.year, pStudents[i].dateOfBirth.month, pStudents[i].dateOfBirth.day);
        if(pStudents[i].gender == 0)
        {
            fprintf(fout, "Male\n");
        }
        else
        {
            fprintf(fout, "Female\n");
        }
        fprintf(fout, "%lf\n", pStudents[i].examResult);
        fprintf(fout, "\n");
    }
}

int getNumberOfStudentsByGender(Student_t *pStudents, int numberOfStudents, enum Gender gender)
{

}

