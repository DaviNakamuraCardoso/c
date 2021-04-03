#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "error.h"
#include "advice.h"


int main(int argc, char* argv)
{
    char* advice[] = {
        "Take smaller bites\r\n",
        "Go for the tight jeans.  No they do NOT make you look fat.\r\n",
        "One word: inappropriate\r\n",
        "Just for today, be honest. Tell your boss what you *really* think.\r\n",
        "You might want to rethink that haircut\r\n"
    };
    int listener_d = socket(PF_INET, SOCK_STREAM, 0);

    /* __________ Bind __________ */
    struct sockaddr_in name;
    name.sin_family = PF_INET;
    name.sin_port = (in_port_t) htons(30000);
    name.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(listener_d, (struct sockaddr *) &name, sizeof(name)) == -1)
    {
        error("Could not bind");
    }

    int reuse = 1;
    if (setsockopt(listener_d, SOL_SOCKET, SO_REUSEADDR, (char *)&reuse, sizeof(int)) == -1)
    {
        error("Could no reuse port");
    }

    /* _________ Listen _________ */
    listen(listener_d, 10);
    puts("Waiting for connections\n");


    while (1)
    {
        /* __________ Accept ________ */
        struct sockaddr_storage client_addr;
        unsigned int address_size = sizeof(client_addr);
        int connect_d = accept(listener_d, (struct sockaddr *)&client_addr, &address_size);

        /* __________ Begin __________ */
        char* msg = advice[rand() % 5];
        send(connect_d, msg, strlen(msg), 0);
        close(connect_d);
    }
    return 0;

}

int read_in(int socket, char* buffer, int len)
{
    char* s = buffer;
    int slen = len;
    int c;
    do
    {
        c = recv(socket, s, len, 0);
        s += c;
        slen -= c;
    } while ((c > 0) && (s[c-1] != '\n'))

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
