#include "pipex.h"
int pipex(int file1, char **commands, int file2, char *envp[])
{
    int     pipes[2];
    pid_t   father;
    pid_t   child;

    pipe(pipes);
    father = fork();
    if (father <= -1)
        ft_error("ERROR the creation of father was unsuccessful", 1);
    if (father == 0)
        ft_father(file1,commands[0], pipes, envp);
    child = fork();
    if (child <= -1)
        ft_error("ERROR the creation of child was unsuccessful", 1);
    if (child == 0)
        ft_child(file2,commands[1],pipes,envp);
    close(pipes[0]);
    close(pipes[1]);
    return(0);
}

int ft_father(int file1,char *commands, int *pipes, char *envp[])
{
    char **c;
    char *path;
    
    dup2(pipes[1], STDOUT_FILENO);
    close(pipes[0]);
    dup2(file1, STDIN_FILENO);
    c = ft_split(commands, ' ');
    path = ft_get_path(c[0], envp);
    if (execve(path, c, envp) == -1)
	{
		ft_error("Error execve", 1);
		exit(1);
	}
    
    return(0);
}
int ft_child( int file2, char *commands, int *pipes,char *envp[])
{
    char **c;
    char *path;

    dup2(pipes[2],STDIN_FILENO);
    close(pipes[1]);
    dup2(file2, STDOUT_FILENO);
    c = ft_split(commands, ' ');
    path = ft_get_path(c[1], envp);
    if (execve(path, c, envp) == -1)
	{
		ft_error("Error execve", 1);
		exit(1);
	}

    return(0);
}
