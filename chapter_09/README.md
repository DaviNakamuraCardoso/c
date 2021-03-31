# Breaking boundaries
## Processes and system calls

### Exercises


#### Code Magnets
```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* now()
{
    time_t t;
    time (&t);
    return asctime(localtime(&t));
}

/* Master control program utility */
/* Records guard patrol check-ins */
int main(void)
{
    char comment[80];
    char cmd[80];

    fgets(comment, 80, stdin);
    sprintf(cmd, "echo '%s %s' >> reports.log", comment, now());
    system(cmd);

    return 0;   
}


```


#### *exec()* function types
| Uses | Character     |
| :------------- | :------------- |
|  List of args       | l       |
| Array/vector of args | v |
| Search in PATH | p |
| Use environment variables | e |

#### Long Exercise
```c
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main(void)
{
    if (execl("/sbin/ifconfig", "/sbin/ifconfig", NULL) == -1)
    {
        if (execlp("ipconfig", "ipconfig", NULL) == -1)
        {
            fprintf(stderr, "Cannot run ifconfig: %s", strerror(errno));
            return 1;
        }
    }
    return 0;
}
```

#### Mixed Messages
Code for the program "coffe":
```c
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
char *w = getenv("EXTRA");
if (!w)
w = getenv("FOOD");
if (!w)
w = argv[argc - 1];
char *c = getenv("EXTRA");
if (!c)
c = argv[argc - 1];
printf("%s with %s\n", c, w);
return 0;
}

```

Test program:
```c
#include <string.h>
#include <stdio.h>
#include <errno.h>
int main(int argc, char *argv[]){

    /* ---------- CODE GOES HERE ------------ */
        fprintf(stderr, "Can't create order: %s\n", strerror(errno));
        return 1;
    }
    return 0;
}
```
![Answer]("./ex0.png")
