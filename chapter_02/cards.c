/* Shuffle some cards and display the result*/

#include <stdio.h>


int main(void)
{
    // Declares a pointer to a constant called 'deck'
    const char* deck = "JQK";

    // Copies the literal string "JQK" to an array with a pointer called cards
    char cards[] = "JQK";
    char a_card = cards[2];

    cards[2] = cards[1];
    cards[1] = cards[0];
    cards[0] = cards[2];
    cards[2] = cards[1];
    cards[1] = a_card;


    puts(cards);

    return 0;
}
