/*
Autor: Marcin Sulewski
Data: 15.11.2016
Program: Sito Eratostenesa.
*/

#include <stdio.h>
#include <stdlib.h>

//-----------------------------------------------------------
//--------------------- PROTOTYPY ---------------------------
//-----------------------------------------------------------

void Interface (void);
void Wypelnij (int tablica[], int zakres2);
void Algorytm (int tablica[], int zakres1, int zakres2);
void LiczbyPierwsze (int tablica[], int zakres1, int zakres2);
void WyswietlLiczbyPierwsze(int tablica[], int zakres1, int zakres2);
void Sprawdz(int liczba);

//-----------------------------------------------------------
//--------------------- FUNKCJA MAIN ------------------------
//-----------------------------------------------------------

int main(void){
    Interface();
    return 0;
}

//-----------------------------------------------------------
//--------------------- FUNKCJE -----------------------------
//-----------------------------------------------------------
// INTERFACE:
void Interface (void){

    int wybor;
    int zakres1 = 0, zakres2 = 0;

    do{
        printf("Prosze podac zakres badanych liczb: ");
        printf("\n\npoczatek: ");
        scanf("%d", &zakres1);
        printf("koniec: ");
        scanf("%d", &zakres2);
            if(zakres2<=zakres1 || zakres1 < 0 || zakres2 < 0) printf("Podano niewlasciwy zakres.\n\n");
    }while(zakres2<=zakres1 || zakres1 < 0 || zakres2 < 0);

        do{
            int tablica[zakres2+1];

            system("cls");
            printf("Obecny zakres badanych liczb: <%d,%d>", zakres1, zakres2);
            printf("\n\nKtory program chcesz uruchomic?\n");
            printf("\n1. Uruchom algorytm sita Eratostenesa.");
            printf("\n2. Wyswietl liczby pierwsze z obecnego zakresu.");
            printf("\n3. Sprawdz, czy podana liczba jest pierwsza.");
            printf("\n4. Zmien zakres badanych liczb.");
            printf("\n\n0. KONIEC");
            printf("\n\n\tWybor: ");
            scanf("%d", &wybor);

        switch(wybor){
                case 0: printf("\n\tZakonczono dzialanie programu.\n");
                        return 0;

                case 1: system("cls");
                        printf("Algorytm sita Eratostenesa:");
                        printf("\nZakres badanych liczb: <%d,%d>", zakres1, zakres2);
                        Wypelnij(tablica, zakres2);
                        Algorytm(tablica, zakres1, zakres2);
                        getch();
                        system("cls");
                        break;

                case 2: system("cls");
                        Wypelnij(tablica, zakres2);
                        WyswietlLiczbyPierwsze(tablica, zakres1, zakres2);
                        getch();
                        system("cls");
                        break;

                case 3: system("cls");
                        printf("Prosze podac liczbe: ");
                        int liczba = 0;
                        scanf("%d", &liczba);
                        Sprawdz(liczba);
                        getch();
                        system("cls");
                        break;

                case 4: system("cls");
                        do{
                            printf("Prosze podac nowy zakres: ");
                            printf("\n\npoczatek: ");
                            scanf("%d", &zakres1);
                            printf("koniec: ");
                            scanf("%d", &zakres2);
                            if(zakres2<=zakres1 || zakres1 < 0 || zakres2 < 0) printf("Podano niewlasciwy zakres.\n\n");
                        }while(zakres2<=zakres1 || zakres1 < 0 || zakres2 < 0);
                        system("cls");
                        break;

                default:printf("\n\tPodano niepoprawna wartosc. Prosze sprobowac ponownie.");
                        getch();
                        system("cls");
                        break;
        }
    }while(wybor!=0);
}
//-----------------------------------------------------------
// Wypelnienie tablicy liczbami z podanego zakresu:
void Wypelnij (int tablica[], int zakres2){
    int i = 0;
    for (i; i <= zakres2; i++){
        tablica[i] = i;
    }
}
//-----------------------------------------------------------
// Sito Eratostenesa:
void Algorytm (int tablica[], int zakres1, int zakres2){
    int i = 0, j = 0;
    for (i = 0; i <= sqrt(zakres2); i++){
            if (tablica[i]>1){
                    if(i >= zakres1){
                    printf("\n\nLiczba pierwsza: %d", i);
                    printf("\nWykreslone elementy: ");
                    }else{
                        printf("\n\nWykreslone liczby spoza zakresu dla liczby pierwszej %d: \n", i);
                    }
                    for(j = 2; i*j <= zakres2; j++){

                        if (tablica[i*j] != 0){
                            tablica[i*j] = 0;
                            printf("%d ", i*j);
                        }
                    }
            }
        }
        printf("\n\nLiczby pierwsze z zakresu <%d, %d> \n", zakres1, zakres2);

        if(zakres1 == 0 || zakres1 == 1){
            zakres1 = 2;
        }

        for (i=zakres1; i <= zakres2; i++){
                if (tablica[i] != 0) printf("%d ", i);
        }
}
//-----------------------------------------------------------
//
void LiczbyPierwsze (int tablica[], int zakres1, int zakres2){

    int i = 0, j = 0;

    for (i = 0; i <= sqrt(zakres2); i++){

            if (tablica[i]>1){
                    for(j = 2; i*j <= zakres2; j++){

                        if (tablica[i*j] != 0){
                                tablica[i*j] = 0;
                        }
                    }
            }
        }
}
//-----------------------------------------------------------
// Wyswietlacz liczb pierwszych z podanego zakresu:
void WyswietlLiczbyPierwsze(int tablica[], int zakres1, int zakres2){
    int i = 0;

    LiczbyPierwsze(tablica, zakres1, zakres2);

    printf("Liczby pierwsze z zakresu <%d,%d> \n\n", zakres1, zakres2);

    if(zakres1 == 0 || zakres1 == 1){
            zakres1 = 2;
    }

    for (i = zakres1; i <= zakres2; i++){
        if (tablica[i] != 0) printf("%d ", i);
    }
}
//-----------------------------------------------------------
// Badanie, czy podana liczba jest liczba pierwsza:
void Sprawdz(int liczba){

    int tablica[liczba+1];
    int i = 0;

    Wypelnij (tablica, liczba+1);
    LiczbyPierwsze(tablica, 0, liczba+1);

            if (tablica[liczba] == liczba) printf("Liczba %d jest pierwsza.", liczba);
            else printf("Liczba %d nie jest pierwsza.", liczba);
        }
