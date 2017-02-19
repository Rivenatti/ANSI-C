#include <stdio.h>
#include <stdlib.h>

// ------------ STRUKTURA -----------
struct wiersz{
    float a1, a2;
};


int main(void){
// wiersz pierwszy:
    struct wiersz pierwszy;
    printf("Prosze podac wspolczynniki w pierwszym wierszu:\n");

    printf("a1 = ");
    scanf("%f", &pierwszy.a1);
    printf("a2 = ");
    scanf("%f", &pierwszy.a2);

// wiersz drugi:
    struct wiersz drugi;
    printf("\nProsze podac wspolczynniki w drugim wierszu:\n");

    printf("a3 = ");
    scanf("%f", &drugi.a1);
    printf("a4 = ");
    scanf("%f", &drugi.a2);

// obliczenie wyznacznika:
    struct macierz WierszPierwszyWynik;

     = pierwszy.a1 * drugi.a2 - pierwszy.a2 * drugi.a1;

    printf("\n\nWyznacznik = %.2f\n\n", wyznacznik);

    return 0;
}
