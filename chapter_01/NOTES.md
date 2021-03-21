

### Exercises

#### Sharpen your pencil
1. Prints *"The deck is hot. Increase bet."* to the console.
2. Prints *"I must not write code in class"* 10 times.
3. Gets a boyfriend name and prints the message: f"Dear {name}.\n\n You are history."
4. Prints *"Hearts"*


#### Code Magnets
```c
/*
* Program to evaluate face values.
* Released under the Vegas Public License.
* (c)2014 The College Blackjack Team.
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char card_name[3];
    puts("Enter the card_name: ");
    scanf("%2s", card_name);
    int val = 0;

    if (card_name[0] == 'K') {
    val = 10;
    } else if (card_name[0] == 'Q') {
        val = 10; 
    } else if (card_name[0] == 'J') {
        val = 10;
    } else if (card_name[0] == 'A')
    {
        val = 11;
    } else {
        val = atoi(card_name);
    }
    printf("The card value is %i\n", val);

    return 0;
}

```
