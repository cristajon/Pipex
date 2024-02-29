/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:52:38 by marvin            #+#    #+#             */
/*   Updated: 2024/02/15 20:52:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
int main(int argc, char *argv[],char *envp[] )
{
    int    file1;
    int    file2;
    char    *command[2];
    
    if(!envp || !*envp)
        ft_error("ERROR in envp input", 1);
    if(argc != 5)
        ft_error("ERROR not correct number of inputs", 1);
    file1 = open(argv[1], O_RDONLY);
    command[0] = argv[2];
    command[1] = argv[3];
    file2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC);
    if (file1 || file2 < 0)
        ft_error("Error", 1);

    return(pipex(file1, command, file2, envp));
}
