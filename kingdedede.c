#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct character_def {
    int height, mass;
    char *name;
    struct character_def *friends;
} character;

void * log_alloc(unsigned long size, int amount)
{
    void *address = malloc(size * amount);
    if(address == NULL)
        perror("Could not malloc : ");
    return address;
}

character * make_the_king(int num_friends, char **friends_names)
{
    character *the_king = (character *) log_alloc(sizeof(character), 1);
    the_king->height = rand() % 10 + 10;
    the_king->mass = rand() % 10000 + 100000;
    the_king->name = "King DEDEDE!";
    the_king->friends = (character *) log_alloc(sizeof(character), num_friends);
    for(int i = 0; i < num_friends; i++) 
    {
        the_king->friends[i].height = rand() % 2 + 1;
        the_king->friends[i].mass = 1;
        the_king->friends[i].name = friends_names[i];
    }
    return the_king;
}

void free_character(character *the_king)
{
    free(the_king->friends);
    free(the_king);
}

int main(int argc, char *argv[])
{
    // Seed random and create the king
    srand(time(0));
    // Remove program call from becoming a friend
    char **mod_argv = (char **) malloc(sizeof(char *) * (argc - 1));
    for(int i = 0; i < argc - 1; i++) mod_argv[i] = argv[i + 1];
    // Make the king and display his friends
    character *the_king = make_the_king(argc - 1, mod_argv);
    printf("%s, has arived at %d meters %d tons", the_king->name, the_king->height, the_king->mass);
    for(int i = 0; i < argc - 1; i++) 
    {
        character temp = the_king->friends[i];
        printf("\n%s, has arived at %d feet %d lbs", temp.name, temp.height, temp.mass);
    }
    // Free the king, or else he's TRAPPED IN RAM :O
    free_character(the_king);
    printf("\n");
    return 0;
}