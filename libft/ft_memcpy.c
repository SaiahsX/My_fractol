/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:12:00 by oadewumi          #+#    #+#             */
/*   Updated: 2023/12/13 11:39:14 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This function copies 'n' bytes from memory area 'src' to memory area 'dst'.*/
/* if the bytes in the memory of src and dst overlap, use function 'memmove'*/
/* the *restrict is not used in the arg because it causes some complications*/
/* void *dst is converted to unsigned char *dest 
&& const void *src is converted to const char *org */
/* in case of null inputs, it was handled by the first 'if' statement*/
/* The return value is the original value of dst*/

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	const char		*org;

	dest = dst;
	org = src;
	i = 0;
	if (!dest && !org)
		return (0);
	while (i < n)
	{
		dest[i] = org[i];
		i++;
	}
	return (dst);
}
