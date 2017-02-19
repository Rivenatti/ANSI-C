/*
Autor: Marcin Sulewski
Data: 14.10.2016
Program: Program pobierajacy od uzytkownika dlugosci bokow trojkata: a, b, c. Nastepnie oblicza i wyswietla:
obwod, pole powierzchni oraz promienie okregow opisanego na trojkacie i wpisanego w ten trojkat.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){

    // Deklaracja zmiennych:
    float a = 0, b = 0, c = 0, p = 0;
    float pole_powierzchni = 0, obwod = 0;
    float promien_opisanego = 0, promien_wpisanego = 0;

    // Pobranie od uzytkownika dlugosci bokow trojkata:
    printf("Prosze podac dlugosc boku a: ");
    scanf("%f", &a);

    printf("Prosze podac dlugosc boku b: ");
    scanf("%f", &b);

    printf("Prosze podac dlugosc boku c: ");
    scanf("%f", &c);

    // Sprawdzenie, czy z podanych przez uzytkownika bokow mozna zbudowac trojkat:
    while (!(a+b>c) || !(a+c>b) || !(b+c>a)){
        system("cls");

        printf("Z podanych bokow nie mozna zbudowac trojkata. Prosze podac inne wartosci: ");

        printf("\n\nProsze podac dlugosc boku a: ");
        scanf("%f", &a);

        printf("Prosze podac dlugosc boku b: ");
        scanf("%f", &b);

        printf("Prosze podac dlugosc boku c: ");
        scanf("%f", &c);
    }

    // Obliczenie obwodu trojkata:
    obwod = a+b+c;

    // Obliczenie parametru p:
    p = obwod/2;

    // Obliczenie pola trojkata:
    pole_powierzchni = sqrt(p*(p-a)*(p-b)*(p-c));

    // Obliczanie promienia okregu opisanego na trojkacie:
    promien_opisanego = (a*b*c)/(4*pole_powierzchni);

    // Obliczanie promienia okregu wpisanego w trojkat:
    promien_wpisanego = (a*b*c)/(4*promien_opisanego*p);

    // Wyswietlenie wynikow:
    system("cls");
    printf("\n\tTrojkat o bokach: %.1f, %.1f, %.1f ma: ", a, b, c);
    printf("\n\n\t\tpole powierzchni rowne: %.1f [j. kw.]", pole_powierzchni);
    printf("\n\t\tobwod rowny: %.1f [j.]", obwod);
    printf("\n\n\t\tPromien okregu opisanego na tym trojkacie wynosi: %.1f [j.]", promien_opisanego);
    printf("\n\t\tPromien okregu wpisanego w ten trojkat wynosi: %.1f [j.]\n\n", promien_wpisanego);
    printf("\t[j. - jednostka]\n\n\n");

    system("pause");
    system("cls");
    return 0;
}
