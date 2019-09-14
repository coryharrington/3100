#include <stdio.h>

int factorial(int n)
{
    int product;
    if(n == 0)
        return 1;
    for(product = 1; n > 1; product *= n, n--);
    return product;
}

int main()
{
    int n;
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Error: Please enter a non-negative integer.\n");
    } else {
        printf("%d\n", factorial(n));
    }
    return 0;
}