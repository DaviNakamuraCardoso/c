#include <stdio.h>
#include <unistd.h>

int main(void)
{
    char* my_env[] = {"JUICE=apple and peach", NULL};
    execle("diner_info", "diner_info", "4", NULL, my_env);

    return 0;

}
