/*
Autor: Marcin Sulewski
Data: 13.01.2017
Program: dzialania na ulamkach.
*/
#include <stdio.h>
#include <stdlib.h>
//----------------- STRUKTURY ----------------
struct ulamek {
    int l;
    int m;
} a;
//--------------- PROTOTYPY -----------------
struct ulamek wypelnij(void);
void wyswietl(struct ulamek nazwa);
struct ulamek dodawanie(struct ulamek jeden, struct ulamek dwa);
struct ulamek odejmowanie(struct ulamek jeden, struct ulamek dwa);
struct ulamek mnozenie(struct ulamek jeden, struct ulamek dwa);
struct ulamek dzielenie(struct ulamek jeden, struct ulamek dwa);
struct ulamek NWD(struct ulamek jeden);
//-------------------------------------------
int main(void){

    //INICJALIZACJA DRUGIEGO ULAMKA
    struct ulamek b;

    //WYPELNIENIE ULAMKOW
    printf("Prosze wypelnic pierwszy ulamek.\n\n");
    a = wypelnij();

    system("cls");

    printf("Prosze wypelnic drugi ulamek.\n\n");
    b = wypelnij();

    //INTERFACE UZYTKOWNIKA
    int w;
    do{
        system("cls");
        w = menu();

        switch(w){
            case 1:     system("cls");  wyswietl(dodawanie(a,b));       getch(); break;
            case 2:     system("cls");  wyswietl(odejmowanie(a,b));     getch(); break;
            case 3:     system("cls");  wyswietl(mnozenie(a,b));        getch(); break;
            case 4:     system("cls");  wyswietl(dzielenie(a,b));       getch(); break;
            case 5:     printf("\n\tZakoczono dzialanie programu\n");   exit(1);
            default:    printf("\n\n\tPodano niepoprawna wartosc");     getch();
        }
    }while(w != 5);

    return 0;
}


//--------------------------- FUNKCJE ------------------------------------
struct ulamek wypelnij(void){
    struct ulamek x;
    printf("\nProsze podac licznik ulamka: ");
    scanf("%d", &x.l);

    do{
    printf("\nProsze podac mianownik ulamka: ");
    scanf("%d", &x.m);
    if(x.m == 0)  printf("\n\tMianownik nie moze byc rowny zero! Prosze podac nowa wartosc...\n");
    }while(x.m == 0);

    return(x);
}
//-----------------------------------------------------------------------------
void wyswietl(struct ulamek nazwa){
    printf("Licznik ulamka: %d", nazwa.l);
    printf("\nMianownik ulamka: %d", nazwa.m);
}
//-----------------------------------------------------------------------------
int menu(void){
    int wybor;
    printf("Ktory program chcesz uruchomic?");
    printf("\n\n1. Dodawanie\n2. Odejmowanie\n3. Mnozenie\n4. Dzielenie\n\n5. KONIEC");
    printf("\n\n\tWybor: ");
    scanf("%d", &wybor);

    return(wybor);
}
//-----------------------------------------------------------------------------
struct ulamek dodawanie(struct ulamek jeden, struct ulamek dwa){
    // * Jezeli ulamek jest skracalny trzeba obliczyc NWD i podzielic licznik i mianownik przez NWD!
    struct ulamek wynik;

    if(jeden.m == dwa.m){
        wynik.l = jeden.l + dwa.l;
        wynik.m = jeden.m;
    }else{
    wynik.l = (jeden.l*dwa.m)+(dwa.l*jeden.m);
    wynik.m = (jeden.m*dwa.m);
    }

    return(NWD(wynik));
}
//-----------------------------------------------------------------------------
struct ulamek odejmowanie(struct ulamek jeden, struct ulamek dwa){
    struct ulamek wynik;

    if(jeden.m == dwa.m){
        wynik.l = jeden.l - dwa.l;
        wynik.m = jeden.m;
    }else{
    wynik.l = (jeden.l*dwa.m)-(dwa.l*jeden.m);
    wynik.m = (jeden.m*dwa.m);
    }

    return(NWD(wynik));
}
//-----------------------------------------------------------------------------
struct ulamek mnozenie(struct ulamek jeden, struct ulamek dwa){
    struct ulamek wynik;

    wynik.l = jeden.l*dwa.l;
    wynik.m = jeden.m*dwa.m;

    return(NWD(wynik));
}
//-----------------------------------------------------------------------------
struct ulamek dzielenie(struct ulamek jeden, struct ulamek dwa){
    struct ulamek wynik;

    wynik.l = jeden.l*dwa.m;
    wynik.m = jeden.m*dwa.l;

    return(NWD(wynik));
}
//-----------------------------------------------------------------------------
struct ulamek NWD(struct ulamek jeden){
    int NWD = 0;

    struct ulamek ulamek;
    ulamek.l = jeden.l;
    ulamek.m = jeden.m;

    while (jeden.l != jeden.m){
        if(jeden.l > jeden.m){
                jeden.l -= jeden.m;
        }else{
                jeden.m -= jeden.l;
        }
    }
    NWD = jeden.l;

    if(NWD > 1){
        ulamek.l /= NWD;
        ulamek.m /= NWD;
    }

    return(ulamek);
}
