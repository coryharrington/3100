#include <stdio.h>
#include <stdlib.h>

int odd_sum(int count, int bound, int sum)
{
    if(sum == 0 && count == 0)
        return 1;
    if(sum < 0 || bound <= 0)
        return 0;
    if(bound % 2 == 0)
        bound--;
    int result = odd_sum(count - 1, bound - 1, sum - bound);
    return !result && bound != 0 ? odd_sum(count, bound - 1, sum) : !result && !bound ? 0 : printf("%d ", bound) - 1;
}

int main(void)
{
    int c, b, s;
    printf("Please enter 3 positive integers: count, bound, and sum:\n");
    if(scanf("%d%d%d", &c, &b, &s) != 3) {
        printf("Please enter 3 integers.\n");
        return 1;
    }
    if(c <= 0 || b <= 0 || s <= 0) {
        printf("Integers must be positive.\n");
        return 1;
    }
    if(odd_sum(c, b, s))
        printf("\n");
    else
        printf("There are no solutions.\n");
    return 0;
}