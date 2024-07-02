/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 20:15:56 by oadewumi          #+#    #+#             */
/*   Updated: 2023/12/13 11:39:39 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	This function prints out a string and n anew line */
/*	In this fuction I called my premade function ft_putstr_fd (using write) 
to write out a string, which also uses has a premade function ft_strlen
(to give the number of bytes required as parameter in the write function) */
/*	In this function I also called my premade function ft_putchar_fd 
to write out a character ( a new line in this case).	*/
/*	The test for this function is just to call ft_putendl_fd and 
specify the string and a number for the file descriptor 	*/

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
