/*
Autor: Marcin Sulewski
Data: 09.12.2016
Program: szyfr Cezara.
*/

//-------------------------------------------------
//------------------ PROTOTYPY---------------------
//-------------------------------------------------
void wyswietl (void);
void szyfr (void);
//----------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>


//-------------------------------------------------
//--------------- FUNKCJA MAIN---------------------
//-------------------------------------------------
int main(){

    int wybor;

    do{
    system("cls");
    printf("1. Wyswietl list.\n2. Zaszyfruj list.\n\n0.KONIEC\n\n\tWybor: ");
    scanf("%d", &wybor);
    switch(wybor){
                    case 0: exit(1);                                    break;
                    case 1: system("cls");    wyswietl();     getch();    break;
                    case 2: system("cls");    szyfr();        getch();    break;

    }
    }while(wybor!=0);

    return 0;
}
//----------------------------------------------------------------


//-------------------------------------------------
//-------------------- FUNKCJE---------------------
//-------------------------------------------------
//----------------------------------------------------------------
// Wyswietl wiadomosc
void wyswietl (void){
    char znak;

    FILE *plik;
    plik = fopen("list.txt", "rt");
    if(plik == NULL){
        printf("Blad otwarcia pliku");
        exit(1);
    }

    while((znak=fgetc(plik))!=EOF){
    switch (znak){
                    case 'π':  putchar('a'); break;
                    case 'Ê':  putchar('c'); break;
                    case 'Í':  putchar('e'); break;
                    case '≥':  putchar('l'); break;
                    case 'Ò':  putchar('n'); break;
                    case 'Û':  putchar('o'); break;
                    case 'ú':  putchar('s'); break;
                    case 'ø':  putchar('z'); break;
                    case 'ü':  putchar('z'); break;
                    case '•':  putchar('A'); break;
                    case '∆':  putchar('C'); break;
                    case ' ':  putchar('E'); break;
                    case '£':  putchar('L'); break;
                    case '—':  putchar('N'); break;
                    case '”':  putchar('O'); break;
                    case 'å':  putchar('S'); break;
                    case 'Ø':  putchar('Z'); break;
                    case 'è':  putchar('Z'); break;
                    case ' ':  putchar(' '); break;
                    case '\n': putchar('\n'); break;
                    default :  putchar(znak); break;
                }
    }
    fclose(plik);
}
//----------------------------------------------------------------
// szyfr Cezara
void szyfr (void){
    int i;
    printf("Prosze podac wartosc o jaka chcesz przesuwac kolejne litery alfabetu: ");
    scanf("%d", &i);

    FILE *plik;
    plik = fopen("list.txt", "rt");
    if(plik == NULL){
        printf("Blad otwarcia pliku");
        exit(1);
    }

    char znak;
    system("cls");
    while((znak=fgetc(plik))!=EOF){
    switch (znak){
                    case 'π':  putchar('a'+i); break;
                    case 'Ê':  putchar('c'+i); break;
                    case 'Í':  putchar('e'+i); break;
                    case '≥':  putchar('l'+i); break;
                    case 'Ò':  putchar('n'+i); break;
                    case 'Û':  putchar('o'+i); break;
                    case 'ú':  putchar('s'+i); break;
                    case 'ø':  putchar('z'+i); break;
                    case 'ü':  putchar('z'+i); break;
                    case '•':  putchar('A'+i); break;
                    case '∆':  putchar('C'+i); break;
                    case ' ':  putchar('E'+i); break;
                    case '£':  putchar('L'+i); break;
                    case '—':  putchar('N'+i); break;
                    case '”':  putchar('O'+i); break;
                    case 'å':  putchar('S'+i); break;
                    case 'Ø':  putchar('Z'+i); break;
                    case 'è':  putchar('Z'+i); break;
                    case ' ':  putchar(' '); break;
                    case '\n': putchar('\n'); break;
                    default :  putchar(znak+i);
                }
    }
    fclose(plik);
}
