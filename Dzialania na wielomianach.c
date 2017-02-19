/*
Autor: Marcin Sulewski
Data: 04.11.2016
Program: Dzialania na wielomianach.
*/

#include <stdio.h>
#include <stdlib.h>

    /* ---------------------------- PROTOTYPY -----------------------------  */

void Interface(int StopienPierwszego, int StopienDrugiego, int Pierwszy[], int Drugi[]);
void Wyswietlacz (int StopienPierwszego, int StopienDrugiego, int Pierwszy[], int Drugi[]);
void Dodawanie(int StopienPierwszego, int StopienDrugiego, int Pierwszy[], int Drugi[]);
void Odejmowanie(int StopienPierwszego, int StopienDrugiego, int Pierwszy[], int Drugi[]);
void Mnozenie(int StopienPierwszego, int StopienDrugiego, int Pierwszy[], int Drugi[]);
void WielomianWynikowy (int StopienWynik, int Wynik[]);

    /* --------------------------- FUNCKJA MAIN --------------------------  */
int main(void){

// Pierwszy wielomian
    int StopienPierwszego = 0;
    int i = 0;

    do{
    printf("Prosze podac stopien pierwszego wielomianu: ");
    scanf("%d", &StopienPierwszego);
        if(StopienPierwszego < 0){printf("\nStopien wielomianu nie moze byc ujemny.\n");}
    } while(StopienPierwszego < 0);

    int Pierwszy [StopienPierwszego];

    system("cls");
    printf("Prosze podac wspolczynniki pierwszego wielomianu:\n\n");

        for(i=0; i <= StopienPierwszego; i++){
                if (StopienPierwszego-i == 1){
                    printf("Prosze podac wspolczynnik przy x: ");
                    scanf("%d", &Pierwszy[StopienPierwszego-i]);
                }else if (StopienPierwszego-i == 0){
                    printf("Prosze podac wyraz wolny: ");
                    scanf("%d", &Pierwszy[StopienPierwszego-i]);
                }else{
                    printf("Prosze podac wspolczynnik przy x^%d: ", StopienPierwszego-i);
                    scanf("%d", &Pierwszy[StopienPierwszego-i]);
                }
        }
 //--------------------------------------------------------------------------------------------------------
 // Drugi wielomian
    system("cls");
    int StopienDrugiego = 0;
    i = 0;

    do{
    printf("Prosze podac stopien drugiego wielomianu: ");
    scanf("%d", &StopienDrugiego);
        if(StopienDrugiego < 0){printf("\nStopien wielomianu nie moze byc ujemny.\n");}
    } while(StopienDrugiego < 0);

    int Drugi [StopienDrugiego];

    system("cls");
    printf("Prosze podac wspolczynniki drugiego wielomianu:\n\n");

        for(i=0; i <= StopienDrugiego; i++){
                if (StopienDrugiego-i == 1){
                    printf("Prosze podac wspolczynnik przy x: ");
                    scanf("%d", &Drugi[StopienDrugiego-i]);
                }else if (StopienDrugiego-i == 0){
                    printf("Prosze podac wyraz wolny: ");
                    scanf("%d", &Drugi[StopienDrugiego-i]);
                }else{
                    printf("Prosze podac wspolczynnik przy x^%d: ", StopienDrugiego-i);
                    scanf("%d", &Drugi[StopienDrugiego-i]);
                }
        }
//--------------------------------------------------------------------------------------------------------
// Interface uzytkownika:

    Interface(StopienPierwszego, StopienDrugiego, Pierwszy, Drugi);

    return 0;
}














    /* ----------------------- FUNKCJE --------------------------  */
//------------------------------------------------------------------------------------------------------
// Interface:
void Interface(int StopienPierwszego, int StopienDrugiego, int Pierwszy[], int Drugi[]){
    int wybor;
    do{
        system("cls");
        printf("Ktore dzialanie na wielomianach wykonac?");
        printf("\n1. Dodawanie\n2. Odejmowanie\n3. Mnozenie\n4. Koniec");
        printf("\n\t\twybierasz: ");
        scanf("%d", &wybor);

        switch(wybor){
            case 1: system("cls");
                    printf("Wybrales dodawanie:\n");
                    Wyswietlacz (StopienPierwszego, StopienDrugiego, Pierwszy, Drugi);
                    Dodawanie(StopienPierwszego, StopienDrugiego, Pierwszy, Drugi);
                    getch();
                    break;

            case 2: system("cls");
                    printf("Wybrales odejmowanie:\n");
                    Wyswietlacz (StopienPierwszego, StopienDrugiego, Pierwszy, Drugi);
                    Odejmowanie(StopienPierwszego, StopienDrugiego, Pierwszy, Drugi);
                    getch();
                    break;

            case 3: system("cls");
                    printf("Wybrales mnozenie:\n");
                    Wyswietlacz (StopienPierwszego, StopienDrugiego, Pierwszy, Drugi);
                    Mnozenie(StopienPierwszego, StopienDrugiego, Pierwszy, Drugi);
                    getch();
                    break;

            case 4: printf("\n\tZakoczyles dzialanie programu.");
                    getch();
                    system("cls");
                    return 0;

           default: printf("\n\tTaka opcja nie jest dostepna.");
                    printf("\n\tNastapilo niespodziewane zakonczenie dzialania programu.");
                    getch();
                    system("cls");
                    return 0;
        }
    } while(wybor!=4);}
//------------------------------------------------------------------------------------------------------
// Wyswietlacz wielomianow:
void Wyswietlacz (int StopienPierwszego, int StopienDrugiego, int Pierwszy[], int Drugi[]){

        int i = 0;

        printf("\nPierwszy wielomian:\t");

        for(i=StopienPierwszego; i >= 0; i--){
                if(i==StopienPierwszego && i != 1 && i!= 0){    printf("%dx^%d ", Pierwszy[i], i);}

                if(i > 1 && i < StopienPierwszego){
                    if      (Pierwszy[i]>0){                    printf("+ %dx^%d ", Pierwszy[i], i);}
                    else if (Pierwszy[i]<0){                    printf("- %dx^%d ", Pierwszy[i]*(-1), i);}
                }

                if(i == 1){
                    if      (i==StopienPierwszego){             printf("%dx ", Pierwszy[i]);}
                    else if (Pierwszy[i]>0){                    printf("+ %dx ", Pierwszy[i]);}
                    else if (Pierwszy[i]<0){                    printf("- %dx ", Pierwszy[i]*(-1));}
                }

                if(i == 0){
                    if      (i == StopienPierwszego){           printf("%d ", Pierwszy[i]);}
                    else if (Pierwszy[i]>0){                    printf("+ %d", Pierwszy[i]);}
                    else if (Pierwszy[i]<0){                    printf("- %d", Pierwszy[i]*(-1));}
                }
        }

        printf("\nDrugi wielomian:\t");

        for(i=StopienDrugiego; i >= 0; i--){
                if(i==StopienDrugiego && i != 1 && i!= 0){      printf("%dx^%d ", Drugi[i], i);}

                if(i > 1 && i < StopienDrugiego){
                    if      (Drugi[i]>0){                       printf("+ %dx^%d ", Drugi[i], i);}
                    else if (Drugi[i]<0){                       printf("- %dx^%d ", Drugi[i]*(-1), i);}
                }

                if(i == 1){
                    if      (i==StopienDrugiego){               printf("%dx ", Drugi[i]);}
                    else if (Drugi[i]>0){                       printf("+ %dx ", Drugi[i]);}
                    else if (Drugi[i]<0){                       printf("- %dx ", Drugi[i]*(-1));}
                }
                if(i == 0){
                    if      (i == StopienDrugiego){             printf("%d ", Drugi[i]);}
                    else if (Drugi[i]>0){                       printf("+ %d", Drugi[i]);}
                    else if (Drugi[i]<0){                       printf("- %d", Drugi[i]*(-1));}
                }
        }

}
//------------------------------------------------------------------------------------------------------
// Dodawanie wielomianow:
void Dodawanie(int StopienPierwszego, int StopienDrugiego, int Pierwszy[], int Drugi[]){

    int i = 0;
    int StopienWynik = 0;

    if (StopienPierwszego >= StopienDrugiego) StopienWynik = StopienPierwszego;
    else StopienWynik = StopienDrugiego;

    int Wynik[StopienWynik];

        for(i=0; i<=StopienWynik; i++){
                if      (i > StopienPierwszego){                            Wynik[i] = Drugi[i];}
                else if (i > StopienDrugiego){                              Wynik[i] = Pierwszy[i];}
                else if (i <= StopienPierwszego && i <= StopienDrugiego){   Wynik[i] = Pierwszy[i] + Drugi[i];}
        }

        WielomianWynikowy (StopienWynik, Wynik);
}
//----------------------------------------------------------------------------------------------------------
// Odejmowanie wielomianow:
void Odejmowanie(int StopienPierwszego, int StopienDrugiego, int Pierwszy[], int Drugi[]){

    int i = 0;
    int StopienWynik = 0;

    if (StopienPierwszego >= StopienDrugiego) StopienWynik = StopienPierwszego;
    else StopienWynik = StopienDrugiego;

    int Wynik[StopienWynik];

        for(i=0; i<=StopienWynik; i++){
                if      (i > StopienPierwszego){                            Wynik[i] = Drugi[i];}
                else if (i > StopienDrugiego){                              Wynik[i] = Pierwszy[i];}
                else if (i <= StopienPierwszego && i <= StopienDrugiego){   Wynik[i] = Pierwszy[i] - Drugi[i];}
        }

        WielomianWynikowy (StopienWynik, Wynik);
}
//----------------------------------------------------------------------------------------------------------
// Mnozenie wielomianow:
void Mnozenie(int StopienPierwszego, int StopienDrugiego, int Pierwszy[], int Drugi[]){

    int i = 0, j = 0;

    int StopienWynikowego;

    if      (StopienPierwszego == 0){   StopienWynikowego = StopienDrugiego;}
    else if (StopienDrugiego   == 0){   StopienWynikowego = StopienPierwszego;}
    else{                               StopienWynikowego = StopienDrugiego+StopienPierwszego;}

    int Wynikowy[StopienWynikowego];

    for(i = 0; i<= StopienWynikowego; i++){
                        Wynikowy[i] = 0;
                    }

//        printf("\nStopien wynikowego: %d", StopienWynikowego);

        do{
            for (i = 0; i<=StopienDrugiego; i++){
            Wynikowy[i+j] = Wynikowy[i+j]+(Pierwszy[j] * Drugi [i]);
 //           printf("\nWynikowy [%d] = %d\t\t Pierwszy[%d] = %d \t Drugi[%d] = %d", i+j, Wynikowy[i+j], j, Pierwszy[j], i, Drugi[i]);
            }
            j++;
        }while (j<=StopienPierwszego);
/*
        printf("\n\nWynik: ");
        for (i = StopienWynikowego; i >= 0; i--){
            printf("%d x^%d ", i, Wynikowy[i], i);
        }
*/

        WielomianWynikowy(StopienWynikowego, Wynikowy);
}
//----------------------------------------------------------------------------------------------------------
// Wyswietlacz wyniku dzialania na wielomianach:
void WielomianWynikowy (int StopienWynik, int Wynik[]){

        printf("\n\nWielomian wynikowy:\t");

        int i = 0;

        for(i=StopienWynik; i >= 0; i--){
                if(i==StopienWynik && i != 1 && i!= 0)   printf("%dx^%d ", Wynik[i], i);

                if(i > 1 && i < StopienWynik){
                    if      (Wynik[i]>0){                printf("+ %dx^%d ", Wynik[i], i);}
                    else if (Wynik[i]<0){                printf("- %dx^%d ", Wynik[i]*(-1), i);}
                }
                if(i == 1){
                    if      (i==StopienWynik){           printf("%dx ", Wynik[i]);}
                    else if (Wynik[i]>0){                printf("+ %dx ", Wynik[i]);}
                    else if (Wynik[i]<0){                printf("- %dx ", Wynik[i]*(-1));}
                }
                if(i == 0){
                    if      (i == StopienWynik){         printf("%d ", Wynik[i]);}
                    else if (Wynik[i]>0){                printf("+ %d", Wynik[i]);}
                    else if (Wynik[i]<0){                printf("- %d", Wynik[i]*(-1));}
                }
        }
}
