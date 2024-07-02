/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:52:42 by oadewumi          #+#    #+#             */
/*   Updated: 2023/12/13 11:39:53 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	This function prints(write) out a string input as the output.	*/
/*	This function uses the write function where we need to 
specify the file descriptor	(fd), and also the number of bytes 
(specified by calling the function ft_strlen - here a char is = 1 byte).	*/
/*	Calling ft_strlen in the wwrite function automates the size required.	*/

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (*s != '\0')
	{
		write (fd, s, ft_strlen(s));
	}
}
