/* This program catalogs and label fishes */
#include <stdio.h>

struct fish
{
    const char* name;
    const char* species;
    unsigned short teeth;
    unsigned short age;
};



void catalog(struct fish f)
{
    printf("%s is a %s with %i teeth. He is %i\n",
        f.name, f.species, f.teeth, f.age
    );
}

void label(struct fish f)
{
    printf("Name: %s\nSpecies: %s\nTeeth: %i\nAge: %i\n",
        f.name, f.species, f.teeth, f.age
    );

}


int main(void)
{
    struct fish snappy = {"Snappy", "Piranha", 69, 4};

    catalog(snappy);
    label(snappy);

    return 0;
}
