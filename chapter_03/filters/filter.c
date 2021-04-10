/* This program stores filter a image  */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "filters.h"


int main(int argc, char* args[])
{

    if (argc <= 1)
    {
        fprintf(stderr, "Must provide a filename or filter option\n");
        return 1;
    }
    char* target = "out.txt";
    char ch;

    char filters[5];


    unsigned short index = 0;


    while ((ch = getopt(argc, args, "o:bgcr")) != EOF)
    {
        //
        switch (ch)
        {
            case 'o':
            {
                target = optarg;
                break;
            }
            case 'b':
            case 'g':
            case 'c':
            case 'r':
            {
                filters[index] = ch;
                index++;
                break;
            }
            default:
            {
                return 1;
            }
        }
    }

    argc -= optind;
    args += optind;

    if (strchr(filters, 'b') != NULL)
    {
        blur(target);
    }

    if (strchr(filters, 'c') != NULL)
    {
        contrast(target);
    }

    if (strchr(filters, 'g') != NULL)
    {
        gray(target);
    }

    if (strchr(filters, 'r') != NULL)
    {
        reflex(target);
    }

    puts("Program finished with exit code 0");


    return 0;

}
