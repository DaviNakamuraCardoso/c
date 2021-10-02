#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "graph.h"

graph_t* new_graph(char* article, unsigned int size)
{
    graph_t* g = (graph_t*) malloc(sizeof(graph_t));

    g->current = article; 
    g->elems = calloc(sizeof(gc_t*), size);

    g->size = size;
    g->i = 0;
    g->full = 0;

    g->buff = calloc(sizeof (char), 10000);
    g->index = new_hash();
    g->names = calloc(sizeof(char*), size);

    for (int i = 0; i < size; i++)
    {
        g->elems[i] = calloc(sizeof(graph_t), size);
        for (int j = 0; j < size; j++)
        {
            g->elems[i][j] = false;
        }
    }

    return g;
}

void add_graph(g, f, t)
    graph_t *g;
    unsigned f, t;
{
   g->elems[f][t] = true; 
}

bool isrelated(g, f, t)
    graph_t *g;
    unsigned f, t;
{
    return g->elems[f][t];
}

void printg(graph_t *g)
{
    unsigned size = g->size;

    printf("digraph {\n");

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (isrelated(g, i, j)) printf("\"%s\" -> \"%s\"\n", g->names[i], g->names[j]);
        }
    }

    printf("}\n");
}

unsigned gindex(graph_t* g, char* url)
{
    int index = search_hash(g->index, url);

    if (index == -1)
    {
        index = add_hash(g->index, url);
        g->names[index] = strdup(url);        
    }

    return index; 
}

