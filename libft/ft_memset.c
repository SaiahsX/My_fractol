/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 15:51:54 by oadewumi          #+#    #+#             */
/*   Updated: 2023/12/13 11:39:27 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This function copies the 'int c'(type casted to an unsigned char) to 
the first 'len' characters of the string pointed to by the argument 'b' */
/* This functions imitates the standard Clibrary function 'void *memset */
/* void *b is an undeclared argument, 
hence an Unsigned char was declared to dereference/assiged to it */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = (unsigned char *) b;
	while (i < len)
	{
		ptr[i] = (unsigned char) c;
		i++;
	}
	return (b);
}
