#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef bool gc_t; 

typedef struct {
    unsigned int size;
    gc_t** elems;

} graph_t;

static graph_t* new_graph(unsigned int size)
{
    graph_t* g = (graph_t*) malloc(sizeof(graph_t));
    g->size = size;
    g->elems = calloc(sizeof(gc_t*), size);

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
            if (isrelated(g, i, j)) printf("%i -> %i\n", i, j);
        }
    }

    printf("}\n");
}


int graph(char* article, unsigned int size)
{
    graph_t *g = new_graph(size);

    add_graph(g, 1, 2);
    add_graph(g, 2, 3);
    add_graph(g, 1, 3);

    printg(g);

    return 0;
}
