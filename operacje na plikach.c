// Rivenatti
#include <stdio.h>
#include <stdlib.h>

//---------------- PROTOTYPY ------------------
void wylosuj (int tablica[], const int ilosc);
int wypisz (int tablica[], const int ilosc);
void zapis (int tablica[], const int ilosc);
int odczyt(void);
//---------------------------------------------

//-------------- MAIN ---------------------
int main(void){

    const int n = 20;
    int tablica[n];
    int wybor;

    do{
        system("cls");
        printf("Ktora opcje wybierasz?\n\n");
        printf("1. Wylosuj\n2. Wypisz\n3. Zapisz\n4. Odczytaj\n\n0. KONIEC");
        printf("\n\n\tWybor: ");
        scanf("%d", &wybor);

        switch(wybor){
                        case 1: wylosuj(tablica, n);
                                getch();
                                break;

                        case 2: system("cls");
                                wypisz(tablica, n);
                                getch();
                                break;

                        case 3: zapis(tablica, n);
                                printf("\nPoprawnie zapisano do pliku!");
                                getch();
                                break;

                        case 4: system("cls");
                                odczyt();
                                getch();
                                break;

                        case 0: printf("\nZakonczono dzialanie programu.\n");
                                exit(1);

                        default:printf("\n\tPodano niepoprawna wartosc!");
                                getch();

        }

    }while(wybor != 0);

    return 0;
}
//------------------------------------------------------------
// wypelnienie tablicy
void wylosuj (int tablica[], const int ilosc){

    int i;
    srand(time(NULL));

    for (i=0; i<ilosc; i++){
        tablica[i] = rand()%50;
    }
    printf("\n\nTablica zostala wypelniona!");
}
//------------------------------------------------------------
// wypisanie elementow tablicy:
int wypisz (int tablica[], const int ilosc){
    int i;
    for(i=0; i<ilosc; i++){
        printf("Tablica [%d] = %d\n", i, tablica[i]);
    }
}
//------------------------------------------------------------
// zapis do pliku:
void zapis (int tablica[], const int ilosc){

    int i;
    FILE *plik;
    plik = fopen("tablica.txt", "w");

    if (plik == NULL){
        printf("Blad otwarcia pliku!");
        exit(1);
    }else{
        for(i=0; i<ilosc; i++){
            fprintf(plik, "Tablica [%d] = %d\n", i, tablica[i]);
        }
    }
    fclose(plik);
}
//------------------------------------------------------------
// odczyt z pliku
int odczyt(void){

    int i;
    FILE *plik;
    char znak;

    plik = fopen("tablica.txt", "r");

    if (plik == NULL){
        printf("Blad otwarcia pliku!");
        exit(1);
    }else{
        while((znak=fgetc(plik))!=EOF){
            putchar(znak);
        }
    }

    fclose(plik);
}
