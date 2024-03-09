/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cosas.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaizkor <ceaizkor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:01:13 by ceaizkor          #+#    #+#             */
/*   Updated: 2024/03/07 17:01:13 by ceaizkor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_len(char *msg)
{
	int i;

  i=0;
  while (msg[i] != '\0')
    i++;
  return (i);
}

int	ft_countl(char *s, char c)
{
    int	i;
      	int	l;

    i = 0;
    l = 0;
    while (s[i] != c && s[i])
    {
        l++;
        i++;
    }
    return (l);
}

int	ft_countw(char *s, char c)
{
    int	i;
    int	w;

    w = 0;
    i = 0;
    while (s[i])
    {
        while (s[i] == c)
            i++;
        if (s[i] != c && s[i])
            w++;
        while (s[i] != c && s[i])
            i++;
    }
    return (w);
}

char	**ft_enter(char **sol, char *s, char c)
{
    int	i;
    int	w;
    int	l;

    i = 0;
    w = 0;
    while (s[i] && w < ft_countw(s, c))
    {
        while (s[i] == c)
            i++;
        if (s[i] != c && s[i])
        {
            sol[w] = malloc(ft_countl(s, c) * sizeof(char));
            if (!sol[w])
                return (NULL);
            l = 0;
            while (s[i] != c && s[i])
                sol[w][l++] = s[i++];
            sol[w][l] = 0;
            w++;
        }
    }
    sol[w] = NULL;
    return (sol);
}

char	**ft_split(char *s, char c)
{
    char	**sol;

    if (!s)
        return (NULL);
    if (!*s)
    {
        sol = malloc(sizeof(char *));
        sol[0] = NULL;
        return (sol);
    }
    sol = malloc((ft_countw(s, c) + 1) * sizeof(char *));
    if (!sol)
        return (NULL);
    return (ft_enter(sol, s, c));


    ///coger un split bueno el de mario puede que este mal
}
