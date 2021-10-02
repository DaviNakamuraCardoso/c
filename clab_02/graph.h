
#ifndef __GRAPHH
#define __GRAPHH

#include "hash.h"
#include <stdbool.h>

typedef bool gc_t; 

typedef struct {
    unsigned int    size, i, full:1;
    gc_t            **elems;
    char            *buff, **names, *current;
    hash_t          *index; 
    

} graph_t;

void printg(graph_t *g);
graph_t* new_graph(char* article, unsigned int size);
void add_graph(graph_t* g, unsigned f, unsigned t);
bool isrelated(graph_t* g, unsigned f, unsigned t);
unsigned gindex(graph_t* g, char* url);

#endif
