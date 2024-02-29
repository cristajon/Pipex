#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdio.h>
# include <strings.h>
# include <ctype.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>

int main(int argc, char *argv[],char *envp[] );
int pipex(int file1, char **commands, int file2, char **envp);
int ft_father(int file1,char *commands, int pipes, char **envp);
int ft_child( int file2, char *commands, int *pipes,char **envp);
int  ft_len(char *msg);
int ft_countl(char const *s, char c);
int ft_countw(char const *s, char c);
char	**ft_enter(char **sol, const char *s, char c);
char    **ft_split(char const *s, char c);
int ft_strncmp(const char *s1, const char *s2, size_t n);
char    ft_get_path(char *command,char envp[]);
void	ft_error(char *msg, int status);
size_t	ft_strlen(const char *str);

#endif
