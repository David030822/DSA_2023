#include "headers/student.h"

int main()
{
    //Student_t student1 = ("Demeter David", "VD0KPF", "Marosvasarhely", 2003, 8, 22, "MALE", 9.33);
    Student_t student2;
    readStudentDetails(&student2);
    printStudent(student2);

    Student_t *students;
    int n;
    freopen("input.txt", "r", stdin);
    scanf("%d", &n);

    students = (Student_t *) calloc(n, sizeof (Student_t));
    if(!students)
    {
        printf("Error allocating memory!\n");
        return -1;
    }

    return 0;
}