// RIVENATII
#include <stdio.h>
#include <stdlib.h>

//------------ PROTOTYPY ------------------
float milimetry (float dl);
float centymetry (float dl);
float kilometry (float dl);
//-----------------------------------------



//-------------- MAIN --------------------
int main(void){

    int wybor;
    float dlugosc;
    float zamiana;

    printf("Prosze podac dlugosc w metrach: ");
    scanf("%f", &dlugosc);

    do{
        system("cls");
        printf("Na jaka jednostke chcesz zamienic?\n\n");
        printf("1. Milimetry.\n2. Centymetry.\n3. Kilometry\n\n0. KONIEC");
        printf("\n\n\tWybor: ");
        scanf("%d", &wybor);

        switch(wybor){
                case 1: system("cls");
                        zamiana = milimetry(dlugosc);
                        printf("%.2f m po zamianie na milimetry wynosi: %.2f mm", dlugosc, zamiana);
                        getch();
                        break;

                case 2: system("cls");
                        zamiana = centymetry(dlugosc);
                        printf("%.2f m po zamianie na centrymetry wynosi: %.2f cm", dlugosc, zamiana);
                        getch();
                        break;

                case 3: system("cls");
                        zamiana = kilometry(dlugosc);
                        printf("%.2f m po zamianie na kilometry wynosi: %.2f km", dlugosc, zamiana);
                        getch();
                        break;

                case 0: printf("\nZakonczono dzialanie programu.\n\n");
                        exit(1);

                default:printf("Podano niepoprawna wartosc.");
                        getch();
        }

    }while(wybor != 0);

    return 0;
}


//-------------- FUNKCJE ----------------------
// Milimetry
float milimetry (float dl){
    float nowaDlugosc;

    nowaDlugosc = dl*1000.0;

    return(nowaDlugosc);
}

// Centymetry
float centymetry (float dl){
    float nowaDlugosc;

    nowaDlugosc = dl*100.0;

    return(nowaDlugosc);
}

// Kilometry
float kilometry (float dl){
    float nowaDlugosc;

    nowaDlugosc = dl/1000.0;

    return(nowaDlugosc);
}
