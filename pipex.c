#include "pipex.h"
void pipex(char *file1, char **commands, char *file2, char *envp))
{
    int     pipes[2];
    pid_t   father;
    pid_t   child;

    pipe(pipes);
    father = fork();
    if (father <= -1)
        error("ERROR the creation of child process was unsuccessful");
    if (father == 0)
        ft_father(file1,commands[0],pipes,envp);
    child = fork();
    if (child <= -1)
        error("ERROR the creation of child was unsuccessful");
    if (child == 0)
        ft_child(file2,commands[1],pipes,envp);
    close(pipes[1]);
    close(pipes[2]);
}

int ft_father(file1,commands[0],pipes,envp)
{
    
    return(0);
}
int ft_child(file2,commands[1],pipes,envp)
{

    return(0);
}
