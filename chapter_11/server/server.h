int open_listener_socket(void);
void bind_to_port(int socket, int port);
int say(int socket, char* s);
void handle_shutdown(int sig);
int read_in(int socket, char* buffer, int len);
void listener_socket(int socket, int queue_len); 
