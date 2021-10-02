#include <stdio.h>
#include "graph.h"

int main(int argc, char** argv)
{
    char* article = "C_(programming_language)";
    if (argc >= 2) article = argv[1];

    graph(article, 20);

    return 0; 
}


