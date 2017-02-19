/*
Autor: Marcin Sulewski
Data: 28.10.2016
Program: obliczanie wartosci pierwiastka.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){

    float liczba = 0, i = 0;
    float przyblizenie = 0.001;

    printf("\n\t\tProsze podac liczbe: ");
    scanf("%f", &liczba);
    i = liczba + 0.1;

    while(fabs(i*i-liczba) > przyblizenie)
    {
        i = (i + liczba/i)/2.0;
    }

    printf("\n\t\tPierwiastek z liczby %.1f wynosi: %.3f", liczba, i);
    getch();
    return 0;
}
