#include <stdio.h>

int main() {
    int i, sum;
    while(i < 200) { sum += i; i += 2; }
    printf("Hello, World!\n%i", sum);
    return 0;
}