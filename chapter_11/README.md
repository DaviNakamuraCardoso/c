# There is no place like 127.0.0.1
## Sockets and networking


### Exercises
#### Sharpen your pencil
```c

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
```

#### Long exercise 
