/*
Autor: Marcin Sulewski
Data: 18.11.2016
Programy: suma cyfr, liczba doskonala i NWD z wykorzystaniem funkcji.
*/

#include <stdio.h>
#include <stdlib.h>

//-----------------------------------------------------------
//--------------------- PROTOTYPY ---------------------------
//-----------------------------------------------------------

int Interface (void);
void SumaCyfr(void);
void LiczbaDoskonala(void);
int NWD(int a, int b);

//-----------------------------------------------------------
//--------------------- FUNKCJA MAIN ------------------------
//-----------------------------------------------------------

int main()
{
    int wybor;

    do{
        wybor = Interface();

        switch(wybor){
                case 0: printf("\n\tZakonczono dzialanie programu.\n");
                        return 0;

                case 1: system("cls");
                        printf("Program obliczajacy sume cyfr podanej przez Ciebie liczby:");
                        SumaCyfr();
                        getch();
                        break;

                case 2: system("cls");
                        printf("Program sprawdzajacy, czy podana przez Ciebie liczba jest doskonala:");
                        LiczbaDoskonala();
                        getch();
                        break;

                case 3: system("cls");
                        int a = 0, b = 0;
                        printf("Program obliczajacy NWD:");
                        printf("\n\nProsze podac pierwsza liczbe: ");
                        scanf("%d", &a);
                        printf("Prosze podac druga liczbe: ");
                        scanf("%d", &b);
                        printf("NWD (%d, %d) = %d", a, b, NWD(a,b));
                        getch();
                        break;

                default:printf("\n\tPodano niepoprawna wartosc. Prosze sprobowac ponownie.");
                        getch();
                        system("cls");
                        break;
        }
    }while(wybor!=0);
    return 0;
}


//-----------------------------------------------------------
//--------------------- FUNKCJE -----------------------------
//-----------------------------------------------------------
// INTERFACE:
int Interface(void){

    int wybor;
    system("cls");
    printf("Ktory program chcesz uruchomic?\n\n");
    printf("1. Suma cyfr liczby");
    printf("\n2. Liczba doskonala");
    printf("\n3. NWD");
    printf("\n\n0. KONIEC");

    printf("\n\n\twybor: ");
    scanf("%d", &wybor);

    return(wybor);
}
//-----------------------------------------------------------
// SUMA CYFR PODANEJ LICZBY:
void SumaCyfr(void){

                int liczby = 0, sum = 0;
                printf("\n\nProsze podac liczbe calkowita dodatnia: ");
                scanf("%d", &liczby);
                do{
                   sum += liczby % 10;
                   liczby /= 10;
                }while(liczby!=0);
                printf("Suma cyfr liczby wynosi: %d", sum);
}
//----------------------------------------------------------------------------
// LICZBA DOSKONALA:
void LiczbaDoskonala(void){

                int liczba = 0, suma = 0, i = 1;
                printf("\n\nProsze podac liczbe: ");
                scanf("%d", &liczba);
                printf("\nDzielniki podanej liczby: ");
                for(i; i<=liczba/2.0; i++){
                    if (liczba % i == 0){
                        suma += i;
                        printf("%d\t", i);
                    }
                }
                printf("\n\nSuma dzielnikow podanej liczby wynosi: %d", suma);
                if(liczba == suma) printf("\n\nJest to liczba doskonala.\n\n");
                else printf("\n\nLiczba nie jest doskonala.\n\n");
}
//----------------------------------------------------------------------------
// NWD:
int NWD(int a, int b){

                while (a != b){
                    if (a>b){
                        a = a - b;
                    } else if (b>a){
                        b = b - a;
                    }
                }
                return (a);
}
