/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:48:33 by oadewumi          #+#    #+#             */
/*   Updated: 2023/12/13 11:40:00 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This function finds the first occurence of a character 'int c' 
(converted to char by typecasting '(char)c'or just plain converion) 
in the string pointed to by 'str'.*/
/* The null terminator character is considered part of the string*/
/*	Removed the condition 'while (str[i])'  and introduced a new variable 
int len that was used to contain the loop within ithe lenght of str	*/
/* The return value is a pointer to the located character or 
Null if the character does not appear in the string*/
/* The return value is the first occurence of the character 
and every other character afterwards */
/* This function imitates the behaviour of the standard Clibrary
function strchr*/

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen((char *)str) + 1;
	while (len > 0)
	{
		if (str[i] == (char) c)
			return ((char *) str + i);
		i++;
		len--;
	}
	return (0);
}
