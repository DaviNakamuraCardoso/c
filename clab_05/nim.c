#include <stdio.h>
#include <unistd.h>


#define MARBLE '#'

void printh(unsigned n); 
unsigned nims(unsigned choice);
unsigned players(unsigned *choice);

int main(void)
{
    unsigned choice = 0; 
    
    for (unsigned num = 16; num > 0; num -= 4)
    {
        printh(num);
        players(&choice);
        nims(choice);
    }

    puts("Dr. Nim wins.");

    return 0;
}

unsigned players(unsigned *choice)
{
    do {
        puts("Player's turn.");
        puts("Choose a number between 1 and 3.");
        scanf("%i", choice);
    } while (*choice < 1 || *choice > 3);

    return choice; 

}

unsigned nims(unsigned choice) 
{
    puts("Dr. Nim's turn."); sleep(1);
    printf("Dr. Nim chose %i\n", 4 - choice); sleep(1);

    return choice;
}

void printh(unsigned n)
{
    printf("Marbles: ");
    for (int i = 0; i < n; i++) putchar(MARBLE);
    putchar('\n');
}
