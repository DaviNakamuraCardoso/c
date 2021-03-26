# Roll your own structures
## structs, unions and bitfields

### Problems

#### ~~Pool~~ Piranha Puzzle
```c
void catalog(struct fish f)
{
    printf("%s is a %s with %i teeth. He is %i\n",
        f.name, f.species, f.teeth, f.age
    );

    return;
}


int main(void)
{
    struct fish snappy = {"Snappy", "Piranha", 69, 4};
    catalog(snappy);

    return 0;
}

```


####  Long Exercise
```c
struct exercise
{
    const char* description;
    float duration;
};

struct meal
{
    const char* ingredients;
    float weight;
};

struct preferences
{
    struct meal food;
    struct exercise exercise;
};

struct fish
{
    const char* name;
    const char* species;
    int teeth;
    int age;
    struct preferences care;
}

```

0. How would you write this data in C?
```c
struct fish snappy = {"Snappy", "Piranha", 69, 4, {{"meat", 0.2}, {"swim in the jacuzzi", 7.5}}};

```
1. Complete the label function so it produces output like this:
```
Name:Snappy
Species:Piranha
4 years old, 69 teeth
Feed with 0.20 lbs of meat and allow to swim in the jacuzzi for 7.50 hours
```

```c
void label(struct fish a)
{
    printf("Name: %s\nSpecies: %s\n%i years old, %i teeth\n",
        a.name, a.species, a.teeth, a.age
    );
    printf("Feed with %2.2f libs of %s and allow to %s for %2.2f hours\n",
        a.care.food.weight, a.care.food.ingredients,
        a.care.exercise.description, a.care.exercise.duration
    );

}

```

#### Exercise
```c
#include <stdio.h>

typedef struct
{
    float tank_capacity;
    int tank_psi;
    const char* suit_material;
} equipment;

typedef struct scuba
{
    const char* name;
    equipment kit;
} diver;

void badge(diver d)
{
    printf("Name: %s Tank: %2.2f(%i) Suit: %s\n",
        d.name, d.kit.tank_capacity, d.kit.tank_psi, d.kit.suit_material);

    return;
}

int main(void)
{
    diver randy = {"Randy", {5.5, 3500, "Neoprene"}};
    badge(randy);

    return 0;
}
```

#### Mixed up mixes

1. ```c margarita m = {2.0, 1.0, {2}}```
2. ```c margarita m = {2.0, 1.0, {0.5}}```
3. ```c margarita m = {2.0, 1.0, {.lime_pieces=1}}```


#### Be the compiler
```c

margarita m = {2.0, 1.0, {0.5}};
```
[x] Compiles
[ ] Does not compile

```c
margarita m;
m = {2.0, 1.0, {0.5}};

```
[ ] Compiles
[x] Does not compile
*Explanation: if the declaration and the assignment are in different lines, the compiler thinks you are creating an array*
