#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *tablica;
    int rozmiar, i;
    printf("Prosze podac rozmiar tablicy: ");
    scanf("%d", &rozmiar);
    tablica = (int *) calloc(rozmiar, sizeof(int));

    srand(time(NULL));

    for(i=0;i<rozmiar; i++){
        tablica[i] = rand()%10;
        printf("Tablica[%d] = %d\n", i, tablica[i]);
    }

    return 0;
}
