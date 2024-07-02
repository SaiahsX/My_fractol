/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:19:18 by oadewumi          #+#    #+#             */
/*   Updated: 2023/12/13 11:40:53 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*This function compares strings 'src' and 'dest' lexicographically 
upto but not more than a specified 'n' characters*/
/* It returns an int value at the first occurence of a difference upto
the specified 'n' characters*/
/* The return vallue is a difference in their ascii character values*/
/* This function imitates the behaviour of standard Clibrary function strncmp*/

#include "libft.h"

int	ft_strncmp(const char *src, const char *dest, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && (src[i] != '\0' || dest[i] != '\0'))
	{
		if (src[i] != dest[i])
		{
			return ((unsigned char) src[i] - (unsigned char) dest[i]);
		}
		i++;
	}
	return (0);
}
