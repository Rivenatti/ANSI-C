// Rivenatti
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//------------- STRUKTURA -----------------
struct wektor{
    float x;
    float y;
    float z;
};
//-----------------------------------------

//---------------- PROTOTYPY --------------
struct wektor wczytaj(void);
float skalarny (struct wektor a, struct wektor b);
struct wektor wektorowy (struct wektor a, struct wektor b);
float dlugosc (struct wektor c);
//-----------------------------------------




//------------------ MAIN ----------------
int main(void){

    int wybor;
    struct wektor a;
    struct wektor b;
    struct wektor i;

    do{
        system("cls");
        printf("Ktora opcje wybierasz?\n\n");
        printf("1. Wprowadz wspolrzedne wektorow.\n2. Iloczyn skalarny wektorow.\n3. Iloczyn wektorowy.\n4. Dlugosc wektorow.\n\n0. KONIEC");
        printf("\n\n\tWybor: ");
        scanf("%d", &wybor);

        switch(wybor){
            case 1:     system("cls");
                        printf("Prosze podac wspolrzedne pierwszego wektora:\n\n");
                        a = wczytaj();
                        printf("\n\nProsze podac wspolrzedne drugiego wektora:\n\n");
                        b = wczytaj();
                        break;

            case 2:     system("cls");
                        printf("Iloczyn skalarny wektorow:\na=[%.2f,%.2f,%.2f]\nb=[%.2f,%.2f,%.2f]\n\nwynosi:\n", a.x, a.y, a.z, b.x, b.y, b.z);
                        printf("%.2f", skalarny(a, b));
                        getch();
                        break;

            case 3:     system("cls");
                        printf("Iloczyn wektorowy wektorow:\na=[%.2f,%.2f,%.2f] x b=[%.2f,%.2f,%.2f] = ", a.x, a.y, a.z, b.x, b.y, b.z);
                        i = wektorowy(a,b);
                        printf("[%.2f, %.2f, %.2f]", i.x, i.y, i.z);
                        getch();
                        break;

            case 4:     system("cls");
                        printf("Dlugosc wektora a=[%.2f,%.2f,%.2f] wynosi: %.2f", a.x, a.y, a.z, dlugosc(a));
                        printf("\nDlugosc wektora b=[%.2f,%.2f,%.2f] wynosi: %.2f", b.x, b.y, b.z, dlugosc(b));
                        getch();
                        getch;
                        break;
        }
    }while(wybor!=0);

    return 0;
}

//----------------- FUNKCJE -------------------
// Pobieranie wektorow:
struct wektor wczytaj(void){
    struct wektor jeden;

    printf("Prosze podac wspolrzedna x: ");
    scanf("%f", &jeden.x);

    printf("Prosze podac wspolrzedna y: ");
    scanf("%f", &jeden.y);

    printf("Prosze podac wspolrzedna z: ");
    scanf("%f", &jeden.z);

    return(jeden);
}
//-----------------------------------
// Iloczyn skalarny:
float skalarny (struct wektor a, struct wektor b){
    float iloczynSkalarny = 0;

    iloczynSkalarny = (a.x)*(b.x)+(a.y)*(b.y)+(a.z)*(b.z);

    return (iloczynSkalarny);
}
//-----------------------------------
// Iloczyn wektorowy:
struct wektor wektorowy (struct wektor a, struct wektor b){
    struct wektor iloczyn;

    iloczyn.x = (a.y)*(b.z) - (a.z)*(b.y);
    iloczyn.y = (a.z)*(b.x) - (a.x)*(b.z);
    iloczyn.z = (a.x)*(b.y) - (a.y)*(b.x);

    return(iloczyn);
}
//-----------------------------------
// Dlugosc wektora:
float dlugosc (struct wektor c){
    float dl;
    dl = pow(pow(c.x,2.0)+pow(c.y,2.0)+pow(c.z,2.0), 1.0/2.0);
    return(dl);
}
