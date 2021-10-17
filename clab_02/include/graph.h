
#ifndef __GRAPHH
#define __GRAPHH

#include "hash.h"
#include <stdbool.h>

typedef unsigned short gc_t; 

typedef struct {
    unsigned int    size, i, full:1, matched:1, done:1, ni, len, links;
    gc_t            **elems;
    char            *buff, **names, *current, *needle, *link;
    unsigned int*   second;
    hash_t          *index; 
    

} graph_t;


typedef struct link {
    gc_t count;
    unsigned int index;

} link_t;


void fprintg(FILE* f, graph_t *g);
graph_t* new_graph(char* article, unsigned int size);
void add_graph(graph_t* g, unsigned f, unsigned t);
bool isrelated(graph_t* g, unsigned f, unsigned t);
int gindex(graph_t* g, char* url);

link_t* relevantlinks(graph_t* g, unsigned int index, 
        unsigned int *realsize);
#endif