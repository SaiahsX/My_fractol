/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 21:05:02 by oadewumi          #+#    #+#             */
/*   Updated: 2023/12/13 11:40:46 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	This function shares a little simiilarity with my function ft_striteri.	*/
/*	This function apples the function 'f' to each character of the string 's'
 and passing its index as the first argument to create a new string with
 memory allocated. Hence, a new result from successive application of 'f'	*/

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*newstr;
	size_t	s_len;

	i = 0;
	s_len = ft_strlen ((char *)s);
	if (!s || !f)
		return (NULL);
	newstr = (char *) malloc ((s_len +1) * sizeof(char));
	if (!newstr)
		return (NULL);
	while (s[i] != '\0')
	{
		newstr[i] = f (i, s[i]);
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
