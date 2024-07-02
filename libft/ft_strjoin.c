/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:32:23 by oadewumi          #+#    #+#             */
/*   Updated: 2024/05/30 19:34:04 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	This function allocates enough memory and returns a new string which is
a result of the conctenation of s1 an s2.	*/
/*	For this function, the variable types of the strings are typecasted &
their lenghts determined via ft_strlen	*/
/*	Removed above 2 new variablles to typecast the variables in the parameter.
This is because ft_strlen got fixed so no need for typecasting.	*/
/*	The operation of ft_strlcpy and ft_strcat was used for the copying	*/
/*	Both source lengths + 1 will serve as the count for the memory allocation
Then make checks if no memory was not allocted and return Null if none	*/
/*	A new variable 'result' is initalized with the allocate memory	*/
/*	return value is the pointer to 'result', the new string	*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	dest_len;
	size_t	source_len;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	dest_len = ft_strlen(s1);
	source_len = ft_strlen(s2);
	result = (char *) malloc ((dest_len + source_len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, dest_len + 1);
	ft_strlcat(result, s2, (dest_len + source_len + 1));
	return (result);
}
