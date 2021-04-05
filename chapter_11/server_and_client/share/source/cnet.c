#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <cnet.h>

// Error handler
void error(char* msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}

int catch_signal(int sig, void (*handler) (int))
{
    struct sigaction action;
    action.sa_handler = handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    return sigaction(sig, &action, NULL);
}

int say(int socket, char* msg)
{
    int status = send(socket, msg, strlen(msg), 0);
    if (status == -1)
    {
        error("Could not send message");
    }

    return status;
}

void bind_server(int socket, int port)
{
    struct sockaddr_in server;
    server.sin_family = PF_INET;
    server.sin_port = (in_port_t) htons(port);
    server.sin_addr.s_addr = htonl(INADDR_ANY);

    int status;
    status = bind(socket, (struct sockaddr *)&server, sizeof(server));
    if (status == -1)
    {
        error("Could not bind to port");
    }

    return;
}

void start_listening(int socket, int len)
{
    int status = listen(socket, len);
    if (status == -1)
    {
        error("Error starting the listening process");
    }
    return;
}


int get_message(int socket, char* buf, int len)
{
    char* s = buf;
    int slen = len;
    int c = recv(socket, s, len, 0);

    while ((c > 0) && (s[c-1] != '\0'))
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
            buf[0] = '\0';
            break;
        }
        default:
        {
            s[c-1] = '\0';
        }
    }
    return (len-slen);
}


void bind_client(int socket, int port)
{

}
