#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "error.h"
#include "server.h"

int listener_d;

int main(void)
{

    catch_signal(SIGINT, handle_shutdown);

    listener_d = open_listener_socket();

    /* ___________ Bind _____________ */
    bind_to_port(listener_d, 30000);

    /* ___________ Listen _____________ */
    listener_socket(listener_d, 10);



    struct sockaddr_storage client_addr;
    unsigned int address_size = sizeof(client_addr);
    char buff[255];

    while (1)
    {
        /* ___________ Accept ___________ */
        int connect_d = accept(listener_d, (struct sockaddr *)&client_addr, &address_size);

        if (connect_d == -1)
        {
            error("Can't open secondary socket!");
        }
        if (!fork())
        {
            close(listener_d);

            /* __________ Begin ___________ */
            say(connect_d, "Knock! Knock!\r\n");

            int status = read_in(connect_d, buff, sizeof(buff));

            if (status == -1)
            {
                fprintf(stderr, "Could not listen to response");
                close(connect_d);
            }

            if (strncasecmp(buff, "Who's there?", 12) != 0)
            {
                say(connect_d, "The Internet Knock Knock Protocol requires you to say 'Who's there?'.\nConnection reset\n");
                close(connect_d);
            }

            say(connect_d, "Oscar\r\n");

            int status2 = read_in(connect_d, buff, sizeof(buff));

            if (status2 == -1)
            {
                fprintf(stderr, "Could not listen to response");
                close(connect_d);
            }

            if (strncasecmp(buff, "Oscar who?", 10) != 0)
            {
                say(connect_d, "The Internet Knock Knock Protocol requires you to say 'Oscar who?'. \nConnection reset\n");
                close(connect_d);
            }
            say(connect_d, "Oscar silly question, you get a silly answer.\r\n");

            close(connect_d);

            exit(0);

        }

        close(connect_d);

    }

}


int open_listener_socket(void)
{
    int s = socket(PF_INET, SOCK_STREAM, 0);
    if (s == -1)
    {
        error("Could not open socket");
    }

    return s;
}


void bind_to_port(int socket, int port)
{
    struct sockaddr_in name;
    name.sin_family = PF_INET;
    name.sin_port = (in_port_t) htons(port);
    name.sin_addr.s_addr = htonl(INADDR_ANY);

    int reuse = 1;
    if (setsockopt(socket, SOL_SOCKET, SO_REUSEADDR, (char*)&reuse, sizeof(int)))
    {
        error("Can't reuse port");
    }

    int c = bind(socket, (struct sockaddr *)&name, sizeof(name));
    if (c == -1)
    {
        error("Can't bind to socket");
    }

    return;

}

void listener_socket(int socket, int queue_len)
{
    if (listen(socket, queue_len) == -1)
    {
        error("Could not start listening to socket");
    }
    puts("Starting server");

    return;
}


int say(int socket, char* s)
{
    int result = send(socket, s, strlen(s), 0);
    if (result == -1)
    {
        fprintf(stderr, "%s: %s\n", "Error talking to the client", strerror(errno));
    }
    return result;
}


void handle_shutdown(int sig)
{
    if (listener_d)
    {
        close(listener_d);
    }
    fprintf(stderr, "Bye!\n");

    exit(0);
}


int read_in(int socket, char* buffer, int len)
{
    char* s = buffer;
    int slen = len;
    int c;
    c = recv(socket, s, len, 0);
    while ((c > 0) && (s[c-1] != '\n'))
    {
        s += c;
        slen -= c;
        c = recv(socket, s, len, 0);
    }

    switch (c)
    {
        case -1:
        {
            return c;
        }
        case 0:
        {
            buffer[0] = '\0';
            break;
        }
        default:
        {
            s[c-1] = '\0';
        }
    }
    return len - slen;
}
