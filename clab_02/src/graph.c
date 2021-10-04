#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <graph.h>

graph_t* new_graph(char* article, unsigned int size)
{
    graph_t* g = (graph_t*) malloc(sizeof(graph_t));

    g->current = article; 
    g->elems = calloc(sizeof(gc_t*), size);

    g->size = size;
    g->i = 0;
    g->full = 0;

    g->buff = calloc(sizeof (char), 10000);
    g->needle = "wiki/";
    g->len = strlen(g->needle);
    g->link = calloc(sizeof(char), 300);
    g->matched = 0;
    g->ni = 0;
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

void fprintg(FILE* f, graph_t *g)
{
    unsigned size = g->size;

    fprintf(f, "digraph {\n");

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i == j) continue; 

            if (isrelated(g, i, j)) 
                fprintf(f, "\"%s\" -> \"%s\"\n", g->names[j], g->names[i]);
        }
    }

    fprintf(f, "}\n");
}

unsigned gindex(graph_t* g, char* url)
{
    int index = search_hash(g->index, url);

    if (index == -1)
    {
        index = add_hash(g->index, url);
        g->names[index] = strdup(url);        
    }

    if (index == 49999) g->full = 1; 

    return index; 
}

