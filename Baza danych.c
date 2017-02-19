//Rivenatti
#include <stdio.h>
#include <stdlib.h>
//----------------- STRUKTURA --------------------
struct osoba{
    char imie [30];
    char nazwisko [50];
    int rokStudiow;
    int semestr;
};
//-----------------------------------------------

//---------------- PROTOTYPY --------------------
void wypelnij (struct osoba student[], int ilosc);
void zapis (struct osoba studenci[], int ile);
//-----------------------------------------------
int main(void){

    int ilosc;
    printf("Prosze podac ilosc danych o studentach do przechowania w bazie.\n\n\tIlosc: ");
    scanf("%d", &ilosc);

    system("cls");

// definicja struktury przechowujacej dane o studentach
    struct osoba student[ilosc];

// interface uzytkownika:
    int wybor;

    int i;


    do{
        system("cls");
        printf("Ktora opcje wybierasz?\n\n");
        printf("1. Wypelnienie bazy danymi.\n2. Zapis danych do pliku.\n3. Odczyt danych z pliku.\n\n0. KONIEC");
        printf("\n\n\tWybierasz: ");
        scanf("%d", &wybor);

        switch(wybor){
                case 1: system("cls");
                        wypelnij(student, ilosc);
                        getch();
                        break;

                case 2: zapis(student, ilosc);
                        getch();
                        break;

                case 3: system("cls");
                        odczyt();
                        getch();
                        break;

                case 0: printf("\nZakonczono dzialanie programu.\n\n");
                        exit(1);

                default:printf("\nWybrano niepoprawna opcje.");
                        getch();

        }

    }while(wybor != 0);






    return 0;
}

//------------------ WYPENIENIE BAZY -----------------------
void wypelnij (struct osoba student[], int ilosc){
    int i;

    for (i = 0; i<ilosc; i++){
            printf("Prosze podac imie studenta: ");
            scanf("%s", &student[i].imie);
            printf("Prosze podac nazwisko studenta: ");
            scanf("%s", &student[i].nazwisko);
            printf("Prosze podac rok studiow: ");
            scanf("%d", &student[i].rokStudiow);
            printf("Prosze podac semestr: ");
            scanf("%d", &student[i].semestr);
        }

    printf("\n\nZakonczono wprowadzanie danych!\n\nNacisnij dowolny przycisk, aby kontynuuowac...");

    /* opcjonalnie wyswietlenie poprawnosci:

        printf("Imie: %s\n", student[0].imie);
        printf("Nazwisko: %s\n", student[0].nazwisko);
        printf("Rok studiow: %d\n", student[0].rokStudiow);
        printf("Semestr: %d", student[0].semestr);

    */
}
//------------------ ZAPIS DO PLIKU ------------------------
void zapis (struct osoba studenci[], int ile){
    int i;
    FILE *plik;

    plik = fopen("baza.txt", "wt");

    for(i = 0; i<ile; i++){
        fprintf(plik, "Imie: %s\n", studenci[0].imie);
        fprintf(plik, "Nazwisko: %s\n", studenci[0].nazwisko);
        fprintf(plik, "Rok studiow: %d\n", studenci[0].rokStudiow);
        fprintf(plik, "Semestr: %d", studenci[0].semestr);
    }

    printf("Zapis zakoczony powodzeniem!");
    fclose(plik);
}
//------------------ ODCZYT Z PLIKU ------------------------
void odczyt(void){
    char znak;

    FILE *odczytywany;

    odczytywany = fopen("baza.txt", "rt");

    if(odczytywany == NULL){
        printf("Nie odnaleziono takiego pliku!");
        exit(1);
    }

    while((znak=fgetc(odczytywany)) != EOF){
        printf("%c", znak);
    }

    fclose(odczytywany);
}
