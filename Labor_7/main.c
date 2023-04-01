#include "headers/market.h"

int main() {

    Vegetable vegetable1 = {"kaposzta", 2.5, 2.2, 0.3, 1.1, 0};
    printToFile(vegetable1);

    Vegetable vegetable2;
    scanf("%[^\n]", vegetable2.name);
    scanf("%lf", &vegetable2.weight);
    scanf("%lf%lf%lf", &vegetable2.tapertek.feherje, &vegetable2.tapertek.zsir, &vegetable2.tapertek.szenhidrat);
    scanf("%d", &vegetable2.colour);
    printf("%s, ", vegetable2.name);
    printf("%lf, ", vegetable2.weight);
    printf("%lf, %lf, %lf, ", vegetable2.tapertek.feherje, vegetable2.tapertek.zsir, vegetable2.tapertek.szenhidrat);
    char colour2[15];
    strcpy(colour2, enumToChar(vegetable2));
    printf("%s\n", colour2);

    return 0;
}
