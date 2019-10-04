#include <stdio.h>
#include <stdlib.h>

/* Search for `count' distinct odd numbers that 
 * are smaller than `bound' and add up to `sum'.  
 *
 * Return value:
 *  1: A solution is found and printed.
 *  0: No solution was found.
 */
double factorial(int n)
{
    double product;
    for(product = 1; n > 1; product *= n, n--);
    return product;
}

double choose(int n, int k)
{
    return factorial(n) / (factorial(n-k) * factorial(k));
}

int odd_sum(int count, int bound, int sum)
{
    // Get and populate int* of odds < bound
    int numodds = bound / 2;
    int *odds = (int*) malloc(numodds *sizeof(int));
    if(odds == NULL)
        perror("Error : ");
    for(int i = 0; i < numodds; odds[i] = i + 1, i += 2);
    // Find all possible combinations, and allocate int*'s for them
    int ncombs = choose(numodds, count);
    int **combs = (int**) malloc(sizeof(int*) * ncombs);
    if(combs == NULL)
        perror("Error : ");

    // Indexes, start at 0
    int *vertices = (int*) malloc(sizeof(int) * count);
    if(vertices == NULL)
        perror("Error : ");
    for(int i = 0; i < count; vertices[i] = 0, i++);

    int c = 0;
    while(c < ncombs)
    {
        // Init
        for(int i = 1; i < count; vertices[i] = vertices[i - 1] + 1, i++);
    populate_combination:
        combs[c] = (int*) malloc(sizeof(int) * count);
        if(combs[c] == NULL)
            perror("Error : ");
        for(int i = 0; i < count; i++)
        {
            combs[c][i] = odds[vertices[i]];
        }
        if(vertices[count - 1] < numodds)
        {
            vertices[count - 1]++;
            c++;
            goto populate_combination;
        }
        else
        {
            vertices[count - ]
            vertices[count - 1] -= count;
        }
        
    }
    return 0;
}

int main(void)
{
    int value;
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
    value = odd_sum(c, b, s);
    if(1) {
        printf("Testing");
        printf("\n");
    }
    else
        printf("There are no solutions.\n");
    return 0;
}