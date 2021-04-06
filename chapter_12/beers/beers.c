#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int beers = 2000000;
pthread_mutex_t a_lock = PTHREAD_MUTEX_INITIALIZER;


void* drink_lots(void* a)
{
    int i;
    for (i = 0; i < 100000; i++)
    {
        pthread_mutex_lock(&a_lock);
        beers--;
        pthread_mutex_unlock(&a_lock);
    }

    return NULL;
}

int main(void)
{
    pthread_t threads[20];
    int t;

    printf("%i bottles of beer.\n", beers);

    for (t = 0; t < 20; t++)
    {
        pthread_create(&threads[t], NULL, drink_lots, NULL);
    }
    void* result;

    for (t = 0; t < 20; t++)
    {
        pthread_join(threads[t], &result);
    }

    printf("There are now %i beers.\n", beers);

    return 0;
}
