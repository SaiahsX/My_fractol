/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:10:21 by oadewumi          #+#    #+#             */
/*   Updated: 2023/12/13 11:40:32 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	This function copies upto 'dstsize -1' characters from 'src' to 
'dst' and null erminating the result if 'dstsize' is not zero	*/
/*	it replaces the characters in the destination & ends with a null terminator
which is the reaon for 'dst[i] = '\0'.	*/
/*	The return values vary iin a sense that if th specified dstsize = 0,
it returns the lenght of src	*/
/*	In this function ft_strlcpy, the 'l' indicates its an integer
return value which is the lenght of the src	*/
/*	For some unknownn reason my function still works if the argument size
dstsize is larger than dst while the original function displays 
overflow error. Needs more investigation	*/
/*	upon investigating, the originl function requires a dest buffer size
to be specified. preferbly larger than the dstsize. While my function
somehow assumes theres enough dest buffer size. since i havent handled it	*/
/*	This function imitates the behaviour of the standard C library strlcpy	*/

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
	{
		while (src[i] != '\0')
			i++;
		return (i);
	}
	while (i < (dstsize - 1) && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}
