//
// Created by David on 2023. 02. 27..
//

#ifndef LABOR_3_STUDENT_H
#define LABOR_3_STUDENT_H
typedef struct Date_t{
    int year;
    int month;
    int day;
}Date_t;

enum GENDER{
    MALE,
    FEMALE
};

typedef struct Student_t{
    char name[51];
    char neptuneCode[9];
    char birthPlace[26];
    Date_t dateOfBirth;
    enum GENDER gender;
    float examResult;
}Student_t;

void readStudentDetails(Student_t *pStudent);

#endif //LABOR_3_STUDENT_H
