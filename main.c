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
    char    *file1;
    char    *file2;
    char    *command[2];
    if(!envp || !*envp)
        error("ERROR in envp input")
    if(argc != 5)
        error("ERROR not correct number of inputs")
    file1 = argv[1];
    command[0] = argv[2];
    command[1] = argv[3];
    file2 = argv[4;]
    
    return(pipex(file1, command, file2, envp));
}
