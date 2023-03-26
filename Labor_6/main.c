#include "headers/patient.h"

int main() {

    Patient_t patient1 = {"Kovacs Otto", "5020304260010", ALLERGIES, 2002, 03, 04};
    printf("1. Patient:\n");
    printf("\t%s, ", patient1.nev);
    printf("%s, ", patient1.cnp);
    printf("%s, ", getDiseaseByEnum(patient1.disease));
    printf("%d. %d. %d\n", patient1.birthdate.year, patient1.birthdate.month, patient1.birthdate.day);

    Patient_t patient2;
    char disease[20];
    printf("Give me the data from the next patient:\n");
    scanf("%[^\n]", patient2.nev);
    scanf("%s", patient2.cnp);
    scanf("%s", disease);
    patient2.disease = getDiseaseByChar(disease);
    scanf("%d%d%d", &patient2.birthdate.year, &patient2.birthdate.month, &patient2.birthdate.day);

    char cnpCopy[14];
    strcpy(cnpCopy, patient2.cnp);

    FILE *fout = fopen(strcat(cnpCopy, ".txt"), "w");
    fprintf(fout, "%s, ", patient2.nev);
    fprintf(fout, "%s, ", patient2.cnp);
    fprintf(fout, "%s, ", getDiseaseByEnum(patient2.disease));
    fprintf(fout, "%d. %d. %d.\n", patient2.birthdate.year, patient2.birthdate.month, patient2.birthdate.day);

    FILE *fin = fopen("patients.txt", "r");

    int capacity, command;
    Queue MedicalCenter;

    scanf("%d", &capacity);
    createQueue(capacity, &MedicalCenter);

    srand(time(0));

    for (int i = 0; i < capacity * 10; ++i) {
        command = rand() % 2;
        scanf("%i", &command);

        if (command == 0 && !isEmpty(MedicalCenter))
            dequeue(&MedicalCenter);
        if (command == 1 && !isFull(MedicalCenter)) {
            Patient_t patient;
            readPatient(&patient, fin);
            enqueue(&MedicalCenter, patient);
        }

        display(MedicalCenter, fout);
        printf("****************************\n");
    }

    destroyQueue(&MedicalCenter);

    return 0;
}
