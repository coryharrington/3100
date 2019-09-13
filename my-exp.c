#include <stdio.h>

double factorial(int n) {
    double product;
    for(product = 1; n > 1; product *= n, n--);
    return product;
}

double x_exp(double x, int n) {
    double product;
    for(product = x; n > 1; product *= x, n--);
    return product;
}

double e_exp(double x, int n) {
    double sum;
    for(sum = 1; n > 0; sum += (x_exp(x, n)/factorial(n)), n--);
    return sum;
}

int main() {
    double x;
    int n;
    while (scanf("%lf%d", &x, &n) == 2)
        printf("exp(%lf)=%.10f\n", x, e_exp(x, n - 1));
    return 0;
}