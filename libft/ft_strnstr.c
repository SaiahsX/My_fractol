/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:42:22 by oadewumi          #+#    #+#             */
/*   Updated: 2023/12/13 11:41:01 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	The ft_strnstr() function locates the 1st occurrence of the null-termi-
nated string 'needle' in the string 'haystack', where not more than 
len characters are searched. 	*/
/*	The variables of the haystack and needle were typecasted to char for 
easy use.	*/
/*	Indexes: i and ni are declared and initalised for 
the haystack and needle respectively.	*/
/*	1st, the condition of an empty needle was made to return the haystack.	*/
/*	The needle is a string of 1 or many characters that make up the string.
a false needle will be a typo or incomplete replica of the real needle.	*/
/*	The needle was made to search haystack incrementally while 
doing so character by character and still checking if needle has been 
completely seen. Also to note the needle counter is reset if it encounters
a false needle. This will allow the comparism to continue	*/
/*	The return values will vary in a sense that if the needle is empty, 
the haystack is returned. If the needle cant be found, null is returned.
If the 'len' < needle, null is returned.	*/
/*	This function imitates the behaviour of the 
standard Clibrary function strnstr	*/

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*hs;
	char	*n;
	size_t	i;
	size_t	ni;

	i = 0;
	ni = 0;
	hs = ((char *) haystack);
	n = ((char *) needle);
	if (*n == 0)
		return (hs);
	while (hs[i] != '\0' && i < len)
	{
		while (hs[i + ni] == n[ni] && (ni + i) < len)
		{
			ni++;
			if (n[ni] == '\0')
				return (hs + i);
		}
		i++;
		ni = 0;
	}
	return (0);
}
