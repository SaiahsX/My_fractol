/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:21:18 by oadewumi          #+#    #+#             */
/*   Updated: 2023/12/13 11:40:06 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	This function allocates enough memory for a copy of the string 's1'.	*/
/*	This function duplicates s1 & returns a pointer to it.	*/
/*	The duplicate is s2. 	*/
/*	In this function, the ft_strlen of typecasted s1 is calcuated & 
to be used for memory allocation. 	*/
/*	s2 is equated to the allocated memory (typecasting calloc too)	*/
/*	+1 is added to the string length(ft_strlen)of s1 for the '\0'	*/
/*	a condition was set to check if insufficienrt memory was allocated, 
if true it returns a NULL.	*/
/*	premade function ft_memcpy is used for the duplicate.	*/

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	s1_len;
	char	*s2;

	s1_len = ft_strlen((char *)s1);
	s2 = (char *) ft_calloc ((s1_len + 1), sizeof(char));
	if (!s2)
		return (NULL);
	ft_memcpy(s2, s1, s1_len);
	return (s2);
}
