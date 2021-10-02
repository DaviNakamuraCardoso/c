#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <curl/curl.h>
#include "graph.h"

unsigned int isurlname(char c)
{
    return isalnum(c) || c == '_' || c == '(' || c == ')';
}

static unsigned int islinkstart(char* str, unsigned int index, int max)
{
    char* needle = "wiki/";

    for (int i = 0; i + index < max && i < 5; i++)
    {
        if (str[i+index] != needle[i]) return 0;
    }

    return 1;
}

static void pushlink(graph_t* g, char* url)
{
    if (g->full) return;

    int index = add_hash(g->index, url);
    g->names[index] = strdup(url);

    add_graph(g, index, gindex(g, g->current));
    return;
}

static int islink(char* str, char* buff, int index, int max)
{
    if (!islinkstart(str, index, max)) return 0;

    int i, j;

    for (j = 0, i = 5; i + index < max && isurlname(str[index+i]); i++, j++)
    {
        buff[j] = str[index+i];
    }

    buff[j] = '\0';


    return 1;
}

static size_t article_handler(char* data, size_t size, size_t nmemb, void* gptr)
{
    graph_t* g = (graph_t*) gptr;
    size_t s = size * nmemb;

    char url[300];

    for (int i = 0; i < s; i++)
    {
        if (islink(data, url, i, s)) 
        {
            pushlink(g, url);
        }
    }

    return 0;

}

void get_page(graph_t* g, char* url)
{

    CURL* c = curl_easy_init();
    curl_easy_setopt(c, CURLOPT_URL, url);
    curl_easy_setopt(c, CURLOPT_WRITEFUNCTION, article_handler);

    // Pass the Graph structure to the callback function
    curl_easy_setopt(c, CURLOPT_WRITEDATA, g);

    curl_easy_perform(c);

    curl_easy_cleanup(c);

    return;

}

unsigned int graph(char* article, unsigned int size)
{
    graph_t *g = new_graph(article, size);
    get_page(g, article); 

    printg(g);

    return 0;
}


