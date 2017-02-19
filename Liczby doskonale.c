/*
Autor: Marcin Sulewski
Data: 07.10.2016
Program: Program wyszukujacy 3 pierwsze liczby doskonale.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void){

    int ilosc_doskonalych = 0;
    long suma_dzielnikow = 0;
    int liczba = 2;
    int dzielnik = 1;

    while (ilosc_doskonalych < 3){
        for(dzielnik; dzielnik < liczba; dzielnik ++){
            if(liczba % dzielnik == 0){
                suma_dzielnikow +=dzielnik;
            }
        }
            if (suma_dzielnikow == liczba){
                ilosc_doskonalych++;
                printf("Liczba: %d jest doskonala. \n", liczba);
            }
        dzielnik = 1;
        suma_dzielnikow = 0;
        liczba ++;
    }
    return 0;
}
