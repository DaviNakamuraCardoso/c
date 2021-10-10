#include <stdio.h>
#include <stdlib.h>

int save(graph_t* g, char* name)
{
}

int load(graph_t* g, char* name)
{
    char filename[300];
    FILE* f;

    sprintf(filename, "assets/%s.pdot", name);
    f = fopen(filename, "r");




    return 0;

}



