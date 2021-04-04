#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include "client.h"

int main(int argc, char* argv[])
{
    int d_sock;
    d_sock = open_socket("", "80");
    char buff[255];

    say(d_sock, "GET / HTTP/1.1\r\n");

    say(d_sock, "Host: \r\n\n\r\n");

    char rec[255];

    int bytes_rcvd = recv(d_sock, rec, 255, 0);

    while (bytes_rcvd)
    {
        if (bytes_rcvd == -1)
        {
            error("Can't read from server");
        }
        rec[bytes_rcvd] = '\0';
        printf("%s", rec);
        bytes_rcvd = recv(d_sock, rec, 255, 0);
    }
    close(d_sock);

    return 0;


}


int open_socket(char* host, char* port)
{
    struct addrinfo *res;
    struct addrinfo hints;

    memset(&hints, 0, sizeof(hints));

    hints.ai_family = PF_INET;
    hints.ai_socktype = SOCK_STREAM;
    if (getaddrinfo(host, port, &hints, &res) == -1)
    {
        error("Can't open socket");
    }

    int d_sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

    if (d_sock == -1)
    {
        error("Can't open socket");
    }

    int c = connect(d_sock, res->ai_addr, res->ai_addrlen);
    freeaddrinfo(res);

    if (c == -1)
    {
        error("Can't connect to server");
    }
    return d_sock;
}

int say(int socket, char* s)
{
    int result = send(socket, s, strlen(s), 0);
    if (result == -1)
    {
        fprintf(stderr, "%s: %s\n", "Error talking to the server", strerror(errno));
    }
    return result;
}

void error(char* msg)
{
    fprintf(stderr, "%s: %s", msg, strerror(errno));
    exit(1);
}
