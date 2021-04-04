#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>


int main(int argc, char* argv[])
{
    int s = socket(PF_INET, SOCK_STREAM, 0);

    struct sockaddr_in si;
    memset(&si, 0, sizeof(si));
    si.sin_family  = PF_INET;
    si.sin_addr.s_addr = inet_addr("204.79.197.200");
    si.sin_port = htons(80);

    connect(s, (struct sockaddr *)&si, sizeof(si));

    return 0;
}
