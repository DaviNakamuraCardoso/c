#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <unistd.h>
#include <graph.h>
#include <strtype.h>
#include <html.h>


static void pushlink(graph_t* g)
{
    if (istrash(g->link)) return;

    int index = gindex(g, g->link);

    if (index == -1) return; 

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

    for (int i = 0; i < s; i++)
    {
        pushc(g, data[i]);
    }

    return s;

}

void get_page(graph_t* g, char* url)
{

    char buff[400]; 

    buff[0] = '\0';
    strcat(buff, "https://en.wikipedia.org/wiki/");
    strcat(buff, url);

    CURL* c = curl_easy_init();
    curl_easy_setopt(c, CURLOPT_URL, buff);

    // Pass the Graph structure to the callback function 
    curl_easy_setopt(c, CURLOPT_WRITEDATA, g);

    curl_easy_setopt(c, CURLOPT_WRITEFUNCTION, article_handler);


    curl_easy_perform(c);

    curl_easy_cleanup(c);

    return;

}

static unsigned save_article(char* article, graph_t* g)
{

    FILE* f;
    char dot[300], svg[300], cmd[300], page[300];

    sprintf(dot, "dotfiles/%s.dot", article);

    f = fopen(dot, "w");

    fprintg(f, g);
    fclose(f);

    sprintf(svg, "assets/%s.svg", article);

    sprintf(cmd, "/usr/bin/sfdp \"%s\" -Tsvg > \"%s\"", dot, svg);

    system(cmd);

    sprintf(page, "html/%s.html", article);

    html(svg, page);

    return 0;

}

unsigned int generate_graph(graph_t* g, unsigned n)
{
    link_t* relevant;
    unsigned int num;

    strcpy(g->link, g->current);
    pushlink(g);
    
    get_page(g, g->current); 

    relevant = relevantlinks(g, 0, &num);

    for (int i = 0; i < num && i < n; i++) g->second[i] = relevant[i].index; 

    free(relevant);

    for (int i = 0; i < num && i < n; i++)
    {
        g->current = g->names[g->second[i]]; 
        get_page(g, g->current);
    } 

    return 0; 
}

unsigned int graph(char* article, unsigned int size)
{
    graph_t *g = new_graph(article, size);
    unsigned pages = 12; 

    generate_graph(g, pages);

    save_article(article, g);

    return 0;
}


