#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <time.h>

int score = 0;

void end_game(int sig)
{
    printf("\nFinal Score: %i\n", score);
    exit(0);
}

int catch_signal(int sig, void (*handler) (int))
{
    struct sigaction action;
    action.sa_handler = handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    return sigaction(sig, &action, NULL);
}


void times_up(int sig)
{
    puts("\nTIME'S UP!");
    raise(SIGINT);

}

void error(char* message)
{
    fprintf(stderr, "%s: %s\n", message, strerror(errno));
    exit(1);
}


int main(void)
{
    catch_signal(SIGALRM, times_up);
    catch_signal(SIGINT, end_game);

    while (1)
    {
        int a = random() % 11;
        int b = random() % 11;

        srandom(time(0));
        char txt[4];

        alarm(5);
        printf("\nWhat is %i times %i?\n", a, b);
        fgets(txt, 4, stdin);
        int answer = atoi(txt);

        if (answer == a * b)
        {
            score++;
        }
        else
        {
            printf("Wrong! Score: %i\n", score);
        }
    }
    return 0;

}
