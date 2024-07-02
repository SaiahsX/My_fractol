/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:47:51 by oadewumi          #+#    #+#             */
/*   Updated: 2023/12/13 11:30:30 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This function is intended to write 'n' zeros to a byte string 's'	*/
/*'void *s' is typecasted to an 'unsigned char *str'	*/
/* Since the function is a void, it returns nothing and in the mains file
we only call the function and pass the reulting string to be printed	*/
/* 'i' is the string index (counter)	*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = (unsigned char *) s;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}
