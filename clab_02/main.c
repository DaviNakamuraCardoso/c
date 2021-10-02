#include <stdio.h>
#include "articles.h"

int main(int argc, char** argv)
{
    char* article = "https://en.wikipedia.org/wiki/C_(programming_language)";
    if (argc >= 2) article = argv[1];

    graph(article, 20);

    return 0; 
}


