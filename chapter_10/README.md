# It's good to talk
## Interprocess communication


### Exercises

#### Sharpen your pencil
```c
int main(int argc, char* argv[])
{
    char* phrase =
}

```

#### Pipes
##### Child process

```c
close(fd[0]);
dup2(fd[1], 1); 

```
| #     | Data Stream     |
| :------------- | :------------- |
| 0       | Standard Input       |
| 1 | ~~Standard output~~ Write to pipe |
| 2 | Standard Error |
| 3 | ~~Read end of the pipe~~|
| 4 | Write end to the pipe |


##### Parent process

```c
dup2(fd[0], 0);
close(fd[1]);

```
| #     | Data Stream     |
| :------------- | :------------- |
| 0       | ~~Standard Input~~ Read end of the pipe  |
| 1 | Standard output|
| 2 | Standard Error |
| 3 | Read end of the pipe|
| 4 | ~~Write end to the pipe~~ |
