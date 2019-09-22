#include <stdio.h>
#include <stdlib.h>

/* This program should print the sum of the elements
 *     1^2, 2^2, 3^2, ..., n^2
 * where n is an integer provided by the user on the
 * command line. Hunt down the bugs and squash them!
 * Seek out the memory leaks and plug them up! */

/* Computes the sum of the first n elements in the array. */
int sum(int n, int* arr)
{
    int i, sum;
    for(i = sum = 0; i < n; sum += arr[i], i++);
    return sum;
}

/* Fills the given array with the values
 * 1^2, 2^2, 3^2, ..., (n-1)^2, n^2. */
void fillSquares(int n, int* arr)
{
    for(int i = 0; i < n; arr[i] = (i+1)*(i+1), i++);
}

/* Reads an integer n from arguments,
 * fills array with squares, and computes
 * the sum of the squares. Prints out the
 * sum before freeing all used memory. */
int main(int argc, char *argv[])
{
    int n;
    int *arr;
    // There must be at least 1 argument after the program
    // although only the first one is used.
    if(argc < 2) {
        printf("usage: ./squares n\n");
        return 1;
    }
    // convert the first argument from a string to a number
    n = atoi(argv[1]);
    if (n <= 0) {
        printf("n must be positive.");
        return 1;
    }
    // We have n int's in the arr
    arr = (int*) malloc(n * sizeof(int));
    fillSquares(n, arr);
    printf("total: %d\n", sum(n, arr));
    free(arr);
    return 0;
}