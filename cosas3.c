/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cosas3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaizkor <ceaizkor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:45:59 by ceaizkor          #+#    #+#             */
/*   Updated: 2024/03/14 17:12:52 by ceaizkor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	unsigned int	i ;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

int	ft_exit(int status)
{
	int	res;

	res = 0;
	if (WIFEXITED(status))
	{
		res = WEXITSTATUS (status);
	}
	return (res);
}
