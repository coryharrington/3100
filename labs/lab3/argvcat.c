#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void my_error(char *s)
{
    perror(s);
    exit(1);
}

int main(int argc, char *argv[])
{
    int i, numchar;
    for(i = numchar = 0; i < argc; numchar += strlen(argv[i]), i++);
    char *buffer = (char*) malloc(numchar);
    if(buffer == NULL)
        my_error("Not enough memory");
    for(i = 0; i < argc; strcat(buffer, argv[i]), i++);
    printf("%s\n", buffer);
    free(buffer);
    return 0;
}