#include <stdio.h>

long long new_catalan_number(int n)
{
    long long num, denom;
    for(num = denom = 1; n > 1; num *= (4*n)-2, denom *= (n + 1), n--);
    return num / denom;
}

long catalan_number(int n)
{
    if (n < 1)
        return 1;
    return ((4*n)-2)*catalan_number(n - 1)/(n+1);
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