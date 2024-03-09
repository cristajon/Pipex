#include "pipex.h"

int pipex(int file1, char **commands, int file2, char *envp[]) {
    int pipes[2];
    int res = 0; // Inicializamos res aquí
    int status;
    pid_t child;

    pipe(pipes); // Movemos la creación del pipe aquí
    child = fork();
    if (child == -1)
        ft_error("ERROR the creation of child was unsuccessful\n", 1);
    if (child == 0) {
        close(pipes[1]); // Cerramos la escritura en el pipe en el hijo
        ft_child(file2, commands[1], pipes, envp);
    } else {
        close(pipes[0]); // Cerramos la lectura del pipe en el padre
        ft_father(file1, commands[0], pipes, envp);
    }

    while (wait(&status) > 0) {
        if (WIFEXITED(status)) {
            res = WEXITSTATUS(status);
        }
    }
    return res;
}

int ft_father(int file1, char *commands, int *pipes, char *envp[]) {
    char **c;
    char *path;

    dup2(file1, STDIN_FILENO);
    dup2(pipes[1], STDOUT_FILENO);
    close(pipes[0]); // Cerramos la lectura del pipe en el padre
    c = ft_split(commands, ' ');
    path = ft_get_path(c[0], envp);
    if (execve(path, c, envp) == -1) {
        ft_error("Error execve\n", 1);
        exit(1);
    }
    return 0;
}

int ft_child(int file2, char *commands, int *pipes, char *envp[]) {
    char **c;
    char *path;

    dup2(pipes[0], STDIN_FILENO);
    dup2(file2, STDOUT_FILENO);
    close(pipes[1]); // Cerramos la escritura en el pipe en el hijo
    c = ft_split(commands, ' ');
    path = ft_get_path(c[0], envp);
    if (execve(path, c, envp) == -1) {
        ft_error("Error execve\n", 1);
        exit(1);
    }
    return 0;
}
