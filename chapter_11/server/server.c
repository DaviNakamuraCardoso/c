#include <sys/socket.h>
#include <arpa/inet.h>
#include "error.h"


int main(void)
{
    int listener_d = socket(PF_INET, SOCK_STREAM, 0);

    /* ___________ Bind _____________ */
    struct sockaddr_in name;

    // This creates a internet port 30000
    name.sin_family = PF_INET;
    name.sin_port = (in_port_t)htons(30000);
    name.sin_addr.s_addr = htonl(INNADR_ANY);

    int c = bind(listener_d, (struct sockaddr *) &name, sizeof(name));

    if (c == -1)
    {
        error("Can't bind socket");
    }

    /* __________ Listen ____________ */
    if (listen(listener_d, 10) == -1)  // Set a max number of connections to 10
    {
        error("Can't listen");
    }

    /* ___________ Accept ___________ */
    struct sockaddr_storage client_addr;
    unsigned int address_size = sizeof(client_addr);
    int connect_d = accept(listener_d, (struct sockaddr *) &client_addr, &address_size);
    if (connect_d == -1)
    {
        error("Can't open secondary socket");
    }

    /* __________ Begin ___________ */
    char* msg = "Internet Knock-Knock Protocol Server\r\nVersion 1.0\r\nKnock! Knock!\r\n";
    if (send(connec_d, msg, strlen(msg), 0) == -1)
    {
        error("Send"); 
    }



}
