/*
* Program to evaluate face values.
* Released under the Vegas Public License.
* (c)2014 The College Blackjack Team.
*/
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    char card_name[3];
    int count = 0;

    while (card_name[0] != 'X')
    {

        puts("Enter the card_name: ");
        scanf("%2s", card_name);
        int val = 0;


        switch(card_name[0])
        {
            case 'K':
            case 'Q':
            case 'J':
            {
                val = 10;
                break;
            }
            case 'X':
            {
                continue;
            }
            case 'A':
            {
                val = 11;
                break;
            }
            default:
            {
                val = atoi(card_name);
                if ((val < 1) || (val > 10))
                {
                    puts("Card must be a number between 1 and 10.\n");
                    continue;
                }
            }
        }


        if ((val > 2) && (val < 7))
        {
            count++;
        }
        else if (val == 10)
        {
            count--;
        }

        printf("Current count: %i\n", count);
    }

    return 0;
}
