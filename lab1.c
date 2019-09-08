#include <stdio.h>

int main() {
    double i, sum, x = 0;
    while (scanf("%lf", &x) == 1) {
        sum += x;
        i++;
        printf("Total=%f Average=%f\n", sum, sum / i); 
    };
    return 0;
}