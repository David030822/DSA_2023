//
// Created by David on 2023. 02. 27..
//

#ifndef LABOR_3_STUDENT_H
#define LABOR_3_STUDENT_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Date_t{
    int year;
    int month;
    int day;
}Date_t;

enum Gender{
    MALE = 0,
    FEMALE
};

typedef struct Student_t{
    char name[51];
    char neptuneCode[9];
    char birthPlace[26];
    Date_t dateOfBirth;
    enum Gender gender;
    double examResult;
}Student_t;

void readStudentDetails(Student_t *pStudent, const char *input);
void printStudent(Student_t student);
void allocateMemoryForStudents(Student_t **dpStudents, int numberOfStudents);
void readAllStudentsDetails(Student_t **dpStudents, const char *input);
void printAllStudents(Student_t *pStudents, int numberOfStudents, const char *destination);
int getNumberOfStudentsByGender(Student_t *pStudents, int numberOfStudents, enum Gender gender);


#endif //LABOR_3_STUDENT_H
