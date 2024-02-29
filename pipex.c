#include "pipex.h"
void pipex(char *file1, char **commands, char *file2, char *envp))
{
    int     pipes[2];
    pid_t   father;
    pid_t   child;

    pipe(pipes);
    father = fork();
    if (father <= -1)
        error("ERROR the creation of father was unsuccessful");
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

int ft_father(char *file1,char **commands[0], int pipes, char *envp)
{
    char *c;
    
    dup2(pipes[1], STDOUT_FILENO);
    close(pipes[0]);
    dup2(file1, STDIN_FILENO);
    c = ft_split(commands[0], ' ');
    ft_get_path(c, envp);
    if (execve(path, c, envp) == -1)
	{
		perror("Error execve");
		exit(1);
	}
    
    return(0);
}
int ft_child(file2,commands[1],pipes,envp)
{
    char *c;
    dup2(pipes[2],STDIN_FILENO);
    close(pipes[1]);
    dup2(file2, STDOUT_FILENO);
    c = ft_split(commands[1], ' ');
    ft_get_path(c, envp);
    if (execve(path, c, envp) == -1)
	{
		perror("Error execve");
		exit(1);
	}

    return(0);
}
