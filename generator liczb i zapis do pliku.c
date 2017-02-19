#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){

    FILE *plik;      // deklaracja zmiennej plikowej (pamietaj, ze FILE z duzej piszemy!)

    plik = fopen("wynik.txt", "wt");  // zostanie utworzony plik o nazwie "wynik.txt" w trybie "write text";

    int i, liczba;
    srand(time(NULL));

    for(i = 0; i<2315; i++){
        liczba = 1.0*(rand()%10001)/100-40;
        fprintf(plik, "%d\n", liczba); // zapisu liczb uzywa funkcji fprintf w taki sposob:
    }                                               // fprintf(nazwaZmiennejPlikowej, "specyfikatorTypu", nazwaZmiennej);




    printf("Zapis zakoczony powodzeniem!\n");   // Po wykonaniu zapisu warto wyswietlic zwykly komunikat printf, ze
                                                // zapis sie powiodl.

    fclose(plik);    // funkcja, ktora zamyka plik.

    return 0;

}

