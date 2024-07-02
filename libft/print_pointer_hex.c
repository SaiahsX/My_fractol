/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer_hex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:25:34 by oadewumi          #+#    #+#             */
/*   Updated: 2024/05/28 16:09:19 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	This is a helper function for my ft_printf with the intent to write out 
	a pointer address by format 'p'.
	This helper function is also inttended to write out hexadecimals with a 
	difference of always having '0x' as a prefix.
	Another helper function ft_putstr is utilised to always write out the 
	prefix '0x' before any other thing.
	If the pointer 'ptr' points to 0 or if its a null pointer, we use the 
	another helper function to write '0' after the prefix '0x'.
	Else, the helper function, print_hexadecimal writes the hexadecimals 
	after the prefix.
	There you go, we have our pointer address addressed.  	*/

#include "libft.h"

void	print_pointer_hex(unsigned long long ptr, t_check *audit)
{
	print_str_fd("0x", audit);
	if (!ptr)
		print_char_fd('0', audit);
	else
		print_hexadecimal(ptr, audit, 'x');
}
