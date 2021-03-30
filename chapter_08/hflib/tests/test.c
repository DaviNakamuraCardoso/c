#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dncll.h>

LINKED_LIST* make_ll(char* a, int b)
{
    LINKED_LIST* l = malloc(sizeof(LINKED_LIST));
    l->name = strdup(a);
    l->value = b;
    l->next = NULL;

    return l;
}

int sort_by_name(const void* a, const void* b)
{
    LINKED_LIST* la = (LINKED_LIST*)a;
    LINKED_LIST* lb = (LINKED_LIST*)b;

    return strcmp(la->name, lb->name);
}

int sort_by_age(const void* a, const void* b)
{
    LINKED_LIST* la = (LINKED_LIST*)a;
    LINKED_LIST* lb = (LINKED_LIST*)b;

    return (la->value)-(lb->value);
}


int main(int argc, char* args[])
{
    printf("I've created a library!\n");

    LINKED_LIST* rogerio = make_ll("Rogerio", 43);

    int val;
    char str[80];
    while (scanf("%i,%79[^\n]\n", &val, str) == 2)
    {
        LINKED_LIST* l = make_ll(str, val);
        addll(l, &rogerio, sort_by_name);
    }

    LINKED_LIST* current = rogerio;
    while (current != NULL)
    {
        printf("%s\n", current->name);
        current = current->next;
    }


    return 0;
}
