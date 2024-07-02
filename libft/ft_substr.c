/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:36:43 by oadewumi          #+#    #+#             */
/*   Updated: 2023/12/13 11:41:19 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	This function creates a substring from the source string 's'. 
while len is the max lent of the substring	*/
/*	To do this, a char pointer to new variable (subs_string) is created	*/
/*	ft_strlen of the (typecasted)source is done since strlen had a char. 	*/
/*	Some checks are performed namely:
1.	if the start index > source length, return the null/ '\0'.(corrected below)
2.	if the len > the difference between source_len & start index,
		perform the operation of len = source_len - start index.
3.	After the allocation memory to the subs_string, check if enough memory
	is allocated, if not return NULL.	*/
/*	The substring is calculated by iterating through the source while
using the start index + source index. Then null terminate the substring.	*/
/*	Update: step 1 return is fauty due to inability to free unallocated memory.
Thus, we use the calloc function to allocate and free the size of an empty
string.	*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*subs_string;
	size_t			i;
	unsigned int	source_len;

	i = 0;
	source_len = ft_strlen((char *) s);
	if (start > source_len)
		return (ft_calloc(1, sizeof(char)));
	if (len > (source_len - start))
		len = source_len - start;
	subs_string = (char *)malloc ((len + 1) * sizeof (char));
	if (!subs_string || !s)
		return (NULL);
	while (i < len)
	{
		subs_string[i] = s[start + i];
		i++;
	}
	subs_string[i] = '\0';
	return (subs_string);
}
