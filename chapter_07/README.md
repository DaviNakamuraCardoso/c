# Chapter 07: Turn your functions up to 11
## Advanced functions

### Code Magnets

```c
void find()
{
    int i;
    puts("Search results");
    puts("--------------------");

    for (i = 0; i < NUM_ADS; i++)
    {
        if (strstr(ADS[i], "sports") && !strstr(ADS[i], "bieber"))
        {
            printf("%s\n", ADS[i]);
        }
    }
    puts("--------------------");

    return;
}
```

### Long Exercise
1. Find someone who likes sports but not bieber
2. Find someone who likes sports or workout
3. Find a non-smoker who likes theater
4. Find someone who likes theater arts or dining  

```c
unsigned int sports_no_bieber(char* s)
{
    return (strstr(s, "sports") && !strstr(s, "bieber"));
}

unsigned int sports_or_workout(char* s)
{
    return (strstr(s, "sports") || strstr(s, "working out"));
}

unsigned int ns_theater(char* s)
{
    return (strstr(s, "NS") && strstr(s, "theater"));
}

unsigned int arts_theater_or_dining(char* s)
{
    return (strstr(s, "arts") || strstr(s, "theater") || strstr(s, "dining"));
}

```


### Long exercise 2
1. Sort integer scores, with the smallest value
```c
int compare_scores(const void* score_a, const void* score_b)
{
    int a = *(int *)score_a;
    int b = *(int *)score_b;
    return a-b;
}
```

2. Sort integer scores, with the largest first
```c
int compare_scores(const void* score_a, const void* score_b)
{
    int a = *(int *)score_a;
    int b = *(int *)score_b;
    return b-a;
}
```

3. Sort the rectangles in area order, smallest first
```c
typedef struct
{
    int width;
    int height;
} rectangle;

int compare_areas(const void* a, const void* b)
{
    rectangle* rect_a = (rectangle *)a;
    rectangle* rect_b = (rectangle *)b;

    return ((rect_a->height) * (rect_a->width)) - ((rect_b->height) * (rect_b->width));

}

```
4. Sort a list of names in alphabetical order, case sensitive
```c
int compare_names(const *void a, const *void)
{
    char** str_a = (char **)a;
    char** str_b = (char **)b;

    return strcmp((*str_a), (*str_b));
}

```

5. Sort the rectangles in area order, largest first
```c
int compare_areas_desc(const *void a, const *void b)
{
    return -compare_areas(a, b);
}

```
6. Sort a the names in reverse alphabetical order
```c
int compare_names_desc(const *void a, const *void b)
{
    return -compare_names(a, b);
}
```

### Long Exercise 3
Write a variadic function that calculates the total price of drinks for the *Head First Lounge*
```c

double price(int count, ...)
{
    va_list drinks;

    va_start(drinks, count);

    int i;
    double total = 0;

    for (i = 0; i < count; i++)
    {
        total += cost(va_arg(drinks, enum drink));
    }
    va_end(drinks);

    return total;
}

```
