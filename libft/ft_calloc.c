/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:31:21 by oadewumi          #+#    #+#             */
/*   Updated: 2023/12/13 11:30:40 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	This function contgiously allocates enough memory for 'count'
objects that are the 'size' bytes of memory each and returns a pointer to 
the allocated memory.	*/
/*	In this function, allocated memory is filled with bytes value of zero	*/
/*	This means an opportunity to call our premade function ft_bzero	*/
/*	To start, a void pointer to a variable 'pntr' is declared	*/
/*	This variable will be used to calculate malloc	*/
/*	In this function, some protective conditions are specified:
1.	check if the count * size exceed max value and return a NULL.
	.	'max_num / count' calculates the maximum number of elements that could 
	be allocated without overflowing the size_t data type.
	.	'max_num / count < size' checks whether the calculated maximum number 
	of elements, when multiplied by size, would result in an overflow.
	.	count && ... ensures that both count is non-zero and the potential 
	overflow condition is checked.
2.	After have memory allocated to 'pntr' the void variable 'pntr'. 
Check if its a Null & return a NULL.	*/
/*	To conclude this function, ft_bzero is used to 
zero all allocated memory bytes.	*/
/*	This function imitates the behaviour of the standard Clibrary funtion
calloc.	*/

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*pntr;
	size_t	byte_size;
	size_t	max_num;

	max_num = SIZE_MAX;
	byte_size = count * size;
	if (count && (max_num / count) < size)
		return (NULL);
	pntr = malloc(byte_size);
	if (pntr == NULL)
		return (NULL);
	ft_bzero(pntr, (byte_size));
	return (pntr);
}
