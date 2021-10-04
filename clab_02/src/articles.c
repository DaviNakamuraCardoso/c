#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <curl/curl.h>
#include <unistd.h>
#include <graph.h>

unsigned int isurlname(char c)
{
    switch (c)
    {
        case '_':
        case '(':
        case ')':
        case '%':
        case '.':
            return 1; 
    }
    return isalnum(c);
}

unsigned int istrash(char* url)
{
    char* garbage[] = {
        "help",
        "file",
        "help",
        "wikipedia"
    };

    if (strcasestr(url, "disambiguation") != NULL) return 1;
    for (int i = 0; i < sizeof(garbage) / sizeof(char*); i++)
    {
        if (strcasecmp(garbage[i], url) == 0) return 1;
    }

    return 0; 
}


static void pushlink(graph_t* g)
{
    if (g->full) return;
    if (istrash(g->link)) return;

    int index = gindex(g, g->link);

    add_graph(g, index, gindex(g, g->current));
    return;
}


static int pushl(graph_t *g, char c)
{
    if (!isurlname(c))
    {
        g->matched = 0;
        g->link[g->i] = '\0';
        g->i = 0;

        pushlink(g);
    }
    else g->link[g->i++] = c; 

    return 0;
}


static int pushc(graph_t *g, char c)
{

//    putchar(c);

    if (g->matched) return pushl(g, c);

    if (c == g->needle[g->ni++])
    {
       if (g->ni == g->len)
       {
           g->matched = 1; 
       } 
    }
    else g->ni = 0;

    return 0;

}


static size_t article_handler(char* data, size_t size, size_t nmemb, void* gptr)
{
    graph_t* g = (graph_t*) gptr;

    size_t s = size * nmemb;
//    printf("%lu bytes\n", s);


    for (int i = 0; i < s; i++)
    {
        pushc(g, data[i]);
    }

    return 0;

}

void get_page(graph_t* g, char* url)
{

    char buff[400]; 

    buff[0] = '\0';
    strcat(buff, "https://en.wikipedia.org/wiki/");
    strcat(buff, url);

    CURL* c = curl_easy_init();
    curl_easy_setopt(c, CURLOPT_URL, buff);
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
    char buff[300], buff2[300], buff3[300];
    get_page(g, article); 

    for (int i = 1; i < 20; i++)
    {
        g->current = g->names[i]; 
        get_page(g, g->current);
    } 

    buff[0] = '\0';
    strcat(buff, article);
    strcat(buff, ".dot");

    FILE* f = fopen(buff, "w");

    fprintg(f, g);

    fclose(f);

    buff2[0] = '\0';
    strcat(buff2, article);
    strcat(buff2, ".svg");

    sprintf(buff3, "/usr/bin/dot \"%s\" -Tsvg > \"assets/%s\"", buff, buff2);
    system(buff3);

    unlink(buff);
    return 0;
}


