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
    g->needle = "/wiki/";
    g->len = strlen(g->needle);
    g->link = calloc(sizeof(char), 300);
    g->second = calloc(sizeof(unsigned int), 20);

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
    if (g->full) return; 
    g->elems[t][f]++; 
}

bool isrelated(g, f, t)
    graph_t *g;
    unsigned f, t;
{
    if (f >= g->size || t >= g->size) return false; 
    return g->elems[f][t];
}

int linkcmp(a, b)
    const void* a, *b;
{
    link_t la = *(link_t*)a;
    link_t lb = *(link_t*)b;

    return lb.count - la.count;
}

void copylist(gc_t *src, link_t *dest, unsigned size)
{
    for (int i = 0; i < size; i++)
    {
        dest[i] = (link_t) {.count=src[i], .index=i};
    }
}

unsigned int nonzerolinks(link_t *sorted, unsigned size)
{
    unsigned start = 0, end = size-1, middle = 0;

    if (sorted[0].count == 0) return 0;

    while (start < end)
    {
        middle = (start + end) / 2;

        if (sorted[middle].count == 0)
        {
            if (sorted[middle-1].count != 0) return middle;
            end = middle - 1;
        }
        else 
        {
            if (sorted[middle+1].count == 0) return middle;
            start = middle + 1;
        }
    }

    return 0;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}
int min(int a, int b)
{
    return (a < b) ? a : b;
}


link_t* relevantlinks(g, index, realsize)
    graph_t* g;
    unsigned int index, *realsize;
{
    link_t* sorted = calloc(sizeof(link_t), g->size);

    copylist(g->elems[index], sorted, g->size);

    qsort(sorted, g->size, sizeof(link_t), linkcmp);

    *realsize = nonzerolinks(sorted, g->size);

    return sorted;
}

void fprintg(FILE* f, graph_t *g)
{
    unsigned size = g->size, realsize;

    fprintf(f, "digraph {\n");

    for (int i = 0; i < size; i++)
    {
       link_t* sorted = relevantlinks(g, i, &realsize);

       for (int j = 0; (j < max(realsize / 40, 10)) && sorted[j].count > 0; j++)
       {
           if (i == sorted[j].index) continue;

           fprintf(f, "\"%s\" -> \"%s\"\n", 
                   g->names[i], 
                   g->names[sorted[j].index]);
       }

       free(sorted);
    }

    fprintf(f, "}\n");
}

int gindex(graph_t* g, char* url)
{
    int index = search_hash(g->index, url);

    if (index == -1)
    {
        if (g->full) return -1;
        index = add_hash(g->index, url);
        g->names[index] = strdup(url);        
    }

    if (index == g->size-1) g->full = 1; 

    return index; 
}

