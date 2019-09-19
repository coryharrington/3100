#include <stdio.h>

void print_int(int n, char *name)
{
    printf("%s\tbin:", name ? name : "");
    for (int i = sizeof(int) * 8 - 1; i >= 0; i --)
       printf("%d", (n >> i) & 1);
    printf(" hex:%08X signed:%10d unsigned:%10u\n", n, n, n);
}

int main() {
    int a, b, r;
    char c;
    while (scanf("%i %c%i", &a, &c, &b) == 3) {
        switch(c) {
            case '+': r = a + b; break;
            case '-': r = a - b; break;
            case '*': r = a * b ; break;
            case '/': r = a / b; break;
            case '%': r = a % b; break;
            case '&': r = a & b; break;
            case '|': r = a | b; break;
            case '^': r = a ^ b; break;
            case 'l': r = a << b; break;
            case 'r': r= a >> b; break;
            default: printf("%c is an unsuported operator", c);
        }
        print_int(a, "a");
        printf("%c\n", c);
        print_int(b, "b");
        printf("=\n");
        print_int(r, "r");
    };
    return 0;
}