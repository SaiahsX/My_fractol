/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsign_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:31:16 by oadewumi          #+#    #+#             */
/*   Updated: 2024/05/28 16:09:34 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	This is a helper function for my *ft_printf* function that handles and 
	writes strings representation of the input integer.
	
	The difference between this function and print_nbr_fd is that this only 
	accepts positive integer argument by virtue of its unsigned int parameter.
	
	If the integer is less than 10. We use helper function *print_char_fd* to 
	perform this while passing 'nb' added to ascii value '0' for conversion 
	into a string.

	If not less, it performs the recurssion to split the integer into its
	individual digits and write each value as string characters to the 
	standard output.	*/

#include "libft.h"

void	print_unsign_fd(unsigned int nb, t_check *audit)
{
	if (nb < 10)
	{
		print_char_fd((nb + '0'), audit);
	}
	if (nb >= 10)
	{
		print_unsign_fd((nb / 10), audit);
		nb = (nb % 10) + '0';
		print_char_fd(nb, audit);
	}
}
