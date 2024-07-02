/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:23:42 by oadewumi          #+#    #+#             */
/*   Updated: 2024/05/28 16:08:52 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	This a helper function for my ft_printf with the intention of writing
	out a character to the standard output.
	
	This function receives a character and struct t_check audit as arguments.
	
	In this function, *t_check audit* is utilised for every process, while
	keeping an account of the count.
	
	```if (audit->error == -1)
		return ;```
		
	This snipet of code was added as a protection if ever an error value 
	of '-1' makes its way to this function.	*/

#include "libft.h"

void	print_char_fd(char c, t_check *audit)
{
	if (audit->error == -1)
		return ;
	if (write (1, &c, 1) < 0)
	{
		audit->error = -1;
		return ;
	}
	else
		audit->count++;
}
