#include <stdio.h>
#include <stdlib.h>

int main(void){

    float a, b, n, d, pierwiastek = 0, x1, x2, fx1, fx2, pi;
    int i;

    printf("Prosze podac a: ");
    scanf("%f", &a);
    printf("Prosze podac b: ");
    scanf("%f", &b);
    printf("Prosze podac n: ");
    scanf("%f", &n);

    d = (b-a)/n;

    for(i = 1; i < n; i++){
        x1 = a+d*(i-1);
        x2 = a+(i*d);
        fx1 = -(x1*x1)+12.0;
        fx2 = -(x2*x2)+12.0;
        pi = ((fx1+fx2)*d)/2.0;
        pierwiastek += pi;
    }

    printf("Pierwiastek = %.2f", pierwiastek);
    return 0;
}
