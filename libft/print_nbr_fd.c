/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:01:32 by oadewumi          #+#    #+#             */
/*   Updated: 2024/05/28 16:09:14 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	This is a helper function for my *ft_printf* function that handles and 
	writes strings representation of the input integer.

	This function receives an integer and the struct t_check audit as arguments.

	Since strings are to be written from integers, we need to handle the 
	extreme cases of INT MIN. This is done explicitly by looking out for 
	**-2147483648** and using our helper function *print_str_fd* to write 
	that out.

	If the string is greater than INT MIN; first we write out the 
	negative sign '-' with helper function *print_char_fd*, then we proceed to 
	convert the integer to positive, then followed by checking if the integer
	is less than 10. We use helper function *print_char_fd* to perform this 
	while passing 'nb' added to ascii value for conversion into a string.

	If not less, it performs the recurssion to split the integer into its
	individual digits and write each value as string characters to the 
	standard output.	*/

#include "libft.h"

void	print_nbr_fd(int nb, t_check *audit)
{
	if (nb == -2147483648)
	{
		print_str_fd("-2147483648", audit);
		return ;
	}
	if (nb < 0)
	{
		print_char_fd(('-'), audit);
		nb *= -1;
	}
	if (nb < 10)
	{
		print_char_fd((nb + '0'), audit);
	}
	if (nb >= 10)
	{
		print_nbr_fd((nb / 10), audit);
		nb = (nb % 10) + '0';
		print_char_fd(nb, audit);
	}
}
