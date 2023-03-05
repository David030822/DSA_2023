//
// Created by David on 2023. 02. 27..
//
#include "student.h"

void readStudentDetails(Student_t *pStudent)
{
    freopen("input.txt", "r", stdin);
    scanf("%[^\n]\n", pStudent -> name);
    scanf("%s\n", pStudent -> neptuneCode);
    scanf("%s\n", pStudent-> birthPlace);
    scanf("%d%d%d", &pStudent -> dateOfBirth.year, &pStudent -> dateOfBirth.month, &pStudent -> dateOfBirth.day);
    scanf("%ud", &pStudent -> gender);
    scanf("%lf", &pStudent -> examResult);
    freopen("CON", "r", stdin);
}

void printStudent(Student_t student)
{
    printf("%s\n", student.name);
    printf("%s\n", student.neptuneCode);
    printf("%s\n", student.birthPlace);
    printf("%d. %d. %d.\n", student.dateOfBirth.year, student.dateOfBirth.month, student.dateOfBirth.day);
    printf("%ud\n", student.gender);
    printf("%lf\n", (double)student.examResult);
}
