#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){


    int wybor;

    do{
        system("cls");
        printf("Ktory program chcesz uruchomic?\n\n");
        printf("Zadanie 1.\nZadanie 2.");
        printf("\n\n\tWybor: ");
        scanf("%d", &wybor);

        switch(wybor){

        case 1:
                printf("Imie: Marcin\n");
                printf("Nazwisko: Sulewski");
                getch();
                break;

        case 2:
                printf("\nWiek studenta: 22 lata");
                printf("\nWiek po przeliczeniu na dni wynosi: %d dni.", (22*12*4*7));
                getch();
                break;

        case 3:
                int x = 10;
                printf("\nLiczba podwojona to: %d", x*2);
                printf("\nKwadrat liczby to: %d", x*x);
                printf("\nSzescian liczby to: %d", x*x*x);
                getch();
                break;

        case 4:
                float r = 10, objetosc;
                objetosc = (4.0/3.0)*3.1416*r*r*r;
                printf("\nObjetosc kuli wynosi: %.2f", objetosc);
                getch();
                break;

        case 5:
                float kwota, podatek = 0.2;
                printf("Prosze podac kwote: ");
                scanf("%f", &kwota);
                kwota = kwota + kwota*podatek;
                printf("Kwota po %.2f procentowym podatku wynosi: %.2f.", podatek*100, kwota);
                getch();
                break;

        case 6:
                float stopy, metry;
                printf("Prosze podac dlugosc w stopach: ");
                scanf("%f", &stopy);
                metry = stopy*0.3048;
                printf("Dlugosc %.2f w stopach, po zamianie na metry wynosi: %.4f m.", stopy, metry);
                getch();
                break;

        case 7:
                int liczba;
                do{
                    printf("Prosze podac liczbe: ");
                    scanf("%d", &liczba);
                    if(liczba<0) printf("\nProsze podac licze dodatnia.\n");
                }while(liczba<0);

                printf("Pierwiastek z liczby wynosi: %.2f", sqrt(liczba));
        }


    }while(wybor != 0);







    return 0;
}
