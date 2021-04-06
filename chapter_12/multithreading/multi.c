#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>
#include "multi.h"


int main(void)
{
    pthread_t t0;
    pthread_t t1;

    // Open the first thread
    if (pthread_create(&t0, NULL, does_not, NULL) == -1)
        error("Could not open first thread");

    // Open the second thread
    if (pthread_create(&t1, NULL, does_too, NULL) == -1)
        error("Could not open second thread");

    // Wait for the threads to wait
    void* result;
    if (pthread_join(t0, &result) == -1)
        error("Could not join the first thread");
    if (pthread_join(t1, &result) == -1)
        error("Could not join the second thread");

    return 0;

}


void* does_not(void* a)
{
    int i = 0;
    for (i = 0; i < 5; i++)
    {
        sleep(1);
        puts("Does not!");
    }

    return NULL;
}


void* does_too(void* a)
{
    int i = 0;
    for (i = 0; i < 5; i++)
    {
        sleep(1);
        puts("Does too!");
    }
    return NULL;
}


void error(char* message)
{
    fprintf(stderr, "%s: %sn\n", message, strerror(errno));
    exit(1);
}
