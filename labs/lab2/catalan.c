#include <stdio.h>

long catalan_number(int n)
{
    long num, denom;
    for(num = denom = 1; n > 1; num *= (4*n)-2, denom *= (n + 1), n--);
    return num / denom;
}

int main(void)
{
    int n;

    while (scanf("%d", &n) == 1) {
        if (n < 0) 
            printf("C(%2d) is not defined.\n", n);
        else 
            printf("C(%2d)=%18ld\n", n, catalan_number(n));
    }
    return 0;
}