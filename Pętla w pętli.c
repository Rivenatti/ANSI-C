#include <stdio.h>
#include <stdlib.h>

int main()
{
    int pierwsza = 0;
    int druga = 0;

    while(pierwsza<=20){
        druga++;

        printf("Pierwsza: %d\n", pierwsza);
        printf("Druga: %d\n", druga);

            if(druga==10){
                druga = 0;
                pierwsza ++;
            }
    }
    return 0;
}
