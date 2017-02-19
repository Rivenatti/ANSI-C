/*
Autor: Marcin Sulewski
Data: 17.01.2017
Program:  Napisac program realizujacy algorytm regresji liniowej  dla n-punktow (xi,yi), gdzie i = 1...n;
metoda najmniejszych kwadratow;
*/
#include <stdio.h>
#include <stdlib.h>
//----------------------- PROTOTYPY ---------------------
int interface(void);
int wczytaj(void);
float Sx(int lp);
float Sy(int lp);
float Sxx(int lp);
float Sxy(int lp);
float Syy(int lp);
float A(int lp);
float B(int lp);
//-----------------------------------------------



//----------------- ZMIENNE GLOBALNE ------------
float *x, *y;
//-----------------------------------------------

//------------------------- MAIN ------------------------
int main(void){

    int wybor, n_pkt;
    do{
        system("cls");
        wybor = interface();
        switch(wybor){

            case 1: system("cls");
                    n_pkt = wczytaj();
                    break;

            case 2: system("cls");
                    wypisz(n_pkt);
                    getch();
                    break;

            case 3: system("cls");
                    printf("a = %.2f", A(n_pkt));
					printf("\nb = %.2f", B(n_pkt));
                    getch();
                    break;

            case 0:     printf("\n\tZakoczono dzialanie programu.\n\n"); exit(1);
            default:    printf("Podano niepoprawna wartosc."); getch();
        }
    }while(wybor!=0);

    return 0;
}


//------------------------------- FUNKCJE ------------------------
// Interface uzytkownika:
int interface(void){
    int w;
    printf("Ktory program chcesz uruchomic?\n\n");
    printf("1. Wczytanie punktow.\n2. Wypisanie punktow.\n3. Aproksymacja\n\n0.KONIEC");
    printf("\n\n\tWybor: ");
    scanf("%d", &w);

    return (w);
}
//----------------------------------------------------
// Wczytywanie punktow
int wczytaj(void){
    int liczba_pkt, i;

    printf("Prosze podac ilosc punktow do aproksymacji met. regresji liniowej: ");
    scanf("%d", &liczba_pkt);

    x = (float*) calloc(liczba_pkt, sizeof(float));
    y = (float*) calloc(liczba_pkt, sizeof(float));

    if(x == NULL || y == NULL){
        puts("\nBlad przydzialu pamieci!");
        exit(1);
    }

    for(i=0; i<liczba_pkt; i++){
        printf("\nProsze podac x[%d]: ", i);
        scanf("%f", &x[i]);

        printf("\nProsze podac y[%d]: ", i);
        scanf("%f", &y[i]);
    }

    return(liczba_pkt);
}
//----------------------------------------------------
// Wypisywanie punktow:
void wypisz(int liczba_pkt){
    int i;

    for(i=0; i<liczba_pkt; i++){
        printf("\n(%.2f, %.2f)", x[i], y[i]);
    }
}
//----------------------------------------------------
// Sx
float Sx(int lp){
    int i;
    float sx = 0;

    for(i=0;i<lp;i++){
        sx += x[i];
    }

    return(sx);
}
//----------------------------------------------------
// Sy
float Sy(int lp){
    int i;
    float sy = 0;

    for(i=0;i<lp;i++){
        sy += y[i];
    }

    return(sy);
}
//----------------------------------------------------
// Sxx
float Sxx(int lp){
    int i;
    float sxx = 0;

    for(i=0;i<lp;i++){
        sxx += x[i]*x[i];
    }

    return(sxx);
}
//----------------------------------------------------
// Sxy
float Sxy(int lp){
    int i;
    float sxy = 0;

    for(i=0;i<lp;i++){
        sxy += x[i]*y[i];
    }

    return(sxy);
}
//----------------------------------------------------
// Syy
float Syy(int lp){
    int i;
    float syy = 0;

    for(i=0;i<lp;i++){
        syy += y[i]*y[i];
    }

    return(syy);
}
//----------------------------------------------------
// Aproksymacja
float A(int lp){
    float a;

    // Dla testow: x1 = 2, x2 = 8, y1 = 3, y2 = 12; wynik: 4

    a = (lp*Sxy(lp) - Sx(lp)*Sy(lp)) / (lp*Sxx(lp)-Sx(lp)*Sx(lp));

    return(a);
}


float B(int lp){
    float b;

    b = (Sxx(lp) * Sy(lp) - Sx(lp)*Sxy(lp)) / (lp*Sxx(lp)-Sx(lp)*Sx(lp)) ;

    return(b);
}
