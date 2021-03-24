# Chapter 02: What are you Pointing at?
## Memory and pointers


### Project: *Head First Lounge Stock Tracker*
#### Pseudocode
- We’ll start with 30 bottles - that’s about 180 glasses
- While there’s still some fizz:
- Display the current stock
- Enter the number of glasses ordered
- Adjust the stock
- Then just go round again
### Problems

#### Code magnets

```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int stock = 180;
    char order_string[3];
    int order;

    while (stock > 0)
    {
        printf("The current stock is: %i\n", stock);
        scanf("%2s", order_string);

        order = atoi(order_string);
        stock = stock - order;

        printf("You ordered %i glasses\n", order);
    }
    puts("We are out of stock, baby!\n");

    return 0;
}

```
#### What's my purpose?
1. strchr: Find the location of a character inside a string
2. strcmp: Compare two strings together
3. strstr: Find the location of a string inside another string  
4. strcpy: Find the length of a string
5. strcat: Concatenate two strings together  

#### Sharpen your pencil
Wich of the functions above should you use for the jukebox program?
strstr

#### What's your hunch?
[x] The string can't be updated
[ ] We're swapping characters outside the string
[ ] The string isn't in memory
[ ] Something else

#### Code magnets
```c
void print_reverse(char* s)
{
    size_t len = strlen(s);
    char* t = s + len -1;
    while (t >= s)
    {
        printf("%c", *t);
        t = t - 1;

    }
    puts(" ");
}

```

#### C-Cross
1. mulberry
2. yrrebwarts
3. sharonfruit
4. tiurfiwik 
5. blueberry
6. yrrebkcalb
7. starfruit
8. tiurfilgu
