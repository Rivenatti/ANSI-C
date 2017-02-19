#include <stdio.h>
#include <stdlib.h>

int main(void){

    float a, b, n, d, pierwiastek = 0, x, fx, pi;
    int i;

    printf("Prosze podac a: ");
    scanf("%f", &a);
    printf("Prosze podac b: ");
    scanf("%f", &b);
    printf("Prosze podac n: ");
    scanf("%f", &n);

    d = (b-a)/n;

    for(i = 1; i < n; i++){
        x = a+i*d;
        fx = -(x*x)+12.0;
        pi = fx*d;
        pierwiastek += pi;
    }

    printf("Pierwiastek = %.2f", pierwiastek);
    return 0;
}
