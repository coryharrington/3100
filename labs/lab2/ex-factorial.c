#include <stdio.h>

double factorial(int n)
{
    double product;
    if(n == 0)
        return 1;
    for(product = 1; n > 1; product *= n, n--);
    return product;
}

int main()
{
    int n;
    if (scanf("%d", &n) != 1) return 1;
    if (n < 0) {
        printf("Error: Please enter a non-negative integer.\n");
        return 0;
    }
    printf("%d\n", (int)factorial(n));
    return 0;
}