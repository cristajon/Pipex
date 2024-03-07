#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdio.h>
# include <strings.h>
# include <ctype.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <stdlib.h>

int     main(int argc, char *argv[],char *envp[] );
int     pipex(int file1, char **commands, int file2, char *envp[]);
int     ft_father(int file1,char *commands, int *pipes, char *envp[]);
int     ft_child( int file2, char *commands, int *pipes,char *envp[]);
int      ft_len(char *msg);
int     ft_countl(char *s, char c);
int     ft_countw(char *s, char c);
char	**ft_enter(char **sol,char *s, char c);
char    **ft_split(char *s, char c);
int     ft_strncmp(char *s1, char *s2, size_t n);
char    *ft_get_path(char *command,char *envp[]);
void	ft_error(char *msg, int status);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);

#endif