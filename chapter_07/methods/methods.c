#include <stdio.h>
#include "dogs.h"
#include "methods.h"

int main(void)
{
    DOG* codie = init("Codie", 29.3);
    codie->bark(codie);
    codie->free(codie);
    
    return 0;
}
