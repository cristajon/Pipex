#include "pipex.h"
void pipex(char *file1, char **commandds, char *file2, char *envp))
{
    int     pipes[2];
    pid_t   father;
    pid_t   child;

    pipe(pipes);
    father = fork();
    if (father <= -1)
        error("ERROR the creation of child process was unsuccessful");
    if (father == 0)
        ft_father();
    child = fork();
    if (child <= -1)
        error("ERROR the creation of child was unsuccessful");
    if (child == 0)
        ft_child();
    close(pipes[1]);
    close(pipes[2]);


    
}