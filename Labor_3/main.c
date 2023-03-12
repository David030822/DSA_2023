#include "headers/student.h"

int main()
{
    Student_t student1 = {"Demeter David", "VD0KPF", "Marosvasarhely", 2003, 8, 22, 0, 9.33};
    printStudent(student1);
    printf("\n");

    Student_t student2;
    readStudentDetails(&student2, "input.txt");
    printStudent(student2);
    printf("\n");

    /*enum Gender x = FEMALE;
    printf("%d", x);*/

    Student_t *students;
    int numberOfStudents;
    FILE *fin = fopen("input2.txt", "r");
    if (!fin)
        exit(-500);
    fscanf(fin, "%d\n", &numberOfStudents);
    printf("The number of students is: %d\n", numberOfStudents);
    allocateMemoryForStudents(&students, numberOfStudents);
    for (int i = 0; i < numberOfStudents; ++i)
    {
        fscanf(fin, "%[^\n]\n", students[i].name);
        fscanf(fin, "%s\n", students[i].neptuneCode);
        fscanf(fin, "%s\n", students[i].birthPlace);
        fscanf(fin, "%d %d %d", &students[i].dateOfBirth.year, &students[i].dateOfBirth.month, &students[i].dateOfBirth.day);
        fscanf(fin, "%d", &students[i].gender);
        fscanf(fin, "%lf\n", &students[i].examResult);
    }
    //readAllStudentsDetails(&students, "input2.txt");
    printAllStudents(students, 5, "output.txt");
    getNumberOfStudentsByGender(students, numberOfStudents, 0);


    return 0;
}
