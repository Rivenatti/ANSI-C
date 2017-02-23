#include <stdio.h>
#include <stdlib.h>

int main(void){
    int liczba, cyfra;
    printf("Podaj liczbe: ");
    scanf("%d", &liczba);
    printf("Liczba po odwroceniu: ");

    while (liczba != 0){
        cyfra = liczba % 10;
        printf("%d", cyfra);
        liczba /= 10;
    }

    getch();
    return 0;
}
