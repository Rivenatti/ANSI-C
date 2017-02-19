/*
Autor: Marcin Sulewski
Data: 07.10.2016
Program: Sprawdzanie, czy liczba jest doskonala.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("liczba: ");
    int liczba;
    int suma_dzielnikow = 0;
    int dzielnik = 1;

    scanf("%d", &liczba);

    system("cls");
    printf("Podana liczba: %d\n\n", liczba);
    printf("Dzielniki liczby :\n\n");

    for(dzielnik; dzielnik<liczba; dzielnik++){
        if(liczba % dzielnik == 0){
            printf("%d\t", dzielnik);
            suma_dzielnikow = suma_dzielnikow + dzielnik;
        }
    }
     printf("\n\nSuma dzielnikow liczby: %d\n\n", suma_dzielnikow);


    if (suma_dzielnikow==liczba){
            printf("Liczba doskonala\n\n");
    }else {
            printf("Liczba niedoskonala\n\n");
    }


    system("pause");
    system("cls");
    printf("\n\n\t\t\tAutor: Marcin Sulewski \n\n");

    return 0;
}
