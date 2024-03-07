/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cosas2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaizkor <ceaizkor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:01:20 by ceaizkor          #+#    #+#             */
/*   Updated: 2024/03/07 17:58:03 by ceaizkor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_get_path(char *command,char *envp[])
{  
  char  **path;
  char	*goodpath;
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
  while (path[j])
	{
		goodpath = ft_strjoin(path[j], command);
		if (access(goodpath, 0) == 0)
			return (goodpath);
		j++;
	}
	ft_error("ERROR: command not found", 1);
	exit(1);
}

int	ft_strncmp(char *s1, char *s2, size_t n)
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

char	*ft_strjoin(char *s1, char *s2)
{
	int		lens1;
	int		lens2;
	int		i;
	char	*s3;

	if (!s2 || !s1)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	s3 = malloc(sizeof(char) * (lens1 + lens2 + 1));
	i = 0;
	if (!s3)
		return (NULL);
	while (i <= lens1)
	{
		s3[i] = s1[i];
		i++;
	}
	i = 0;
	while (i <= lens2)
	{
		s3[lens1 + i] = s2[i];
		i++;
	}
	return (s3);
}

size_t	ft_strlen(char *str)
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
	write(1, msg, ft_strlen(msg));
	exit(status);
}