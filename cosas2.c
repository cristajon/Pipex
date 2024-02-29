#include <pipex.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*aux1;
	unsigned char	*aux2;

	aux1 = (unsigned char *) s1;
	aux2 = (unsigned char *) s2;
	i = 0;
	while ((aux1[i] != '\0' || aux2[i] != '\0') && i < n)
	{
		if (aux1[i] == aux2[i])
			i++;
		else
			return (aux1[i] - aux2[i]);
	}
	return (0);
}

ft_get_path(char *command,char envp[])
{  
  char  *path;
  int    i;
  int    j;

  i = 0;
  j = 0;
  
  if (command[0] == '/' && access(command, 0) == 0)
		return (command);
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
	  i++;
	path = ft_split(envp[i] + 5, ':');
	command = ft_strjoin("/", command);
  while (paths[j])
	{
		goodpath = ft_strjoin(path[j], command);
		if (access(goodpath, 0) == 0)
			return (goodpath);
		j++;
	}
	ft_error("ERROR: command not found", 1);
	exit(1);
}
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_error(char *msg, int status)
{
	int len;

	len = 0;

	write(1, msg, ft_strlen);
	exit(status);
}
