void error(char* msg);
int catch_signal(int sig, void (*handler) (int));
int say(int socket, char* msg);
int get_message(int socket, char* buf, int len); 
