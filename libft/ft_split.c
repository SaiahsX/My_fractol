/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:28:55 by oadewumi          #+#    #+#             */
/*   Updated: 2023/12/15 14:58:46 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	This function allocates memory and returns an array of strings 
obtained by splitting the string 's' using the character 'c'as a delimiter.
The array must also end with a null pointer.	*/
/*	The function was broken down to 3 parts:
1:	ft_substr_poll to count through the 's' & return the # of substrings.
2:	ft_split (primary function) to allocate needed memory & return result.
3:	ft_free_function to free allocate memory when done.
4:	ft_filling_substr to print out each substr, using my fxn ft_substr.	*/
/*	In the ft_filling_substr, we start by eliminating the delimiter &
we copy each substring into the allocated memory space in spit_res. We use
the index 'J' to loop through the substrings and important to free the 
allocated memories if there is a failled memory allocation. Then loop
through index 'J' only after this.	*/
/*	The each split result (substings) at the address 'j' is null terminated. 
and returned as our needed output	*/

#include "libft.h"

static size_t	ft_substr_poll(char const *str, char c)
{
	int	count;
	int	in_substring;

	count = 0;
	in_substring = 0;
	while (*str)
	{
		if (*str && *str != c && in_substring == 0)
		{
			in_substring = 1;
			count++;
		}
		else if (*str == c && in_substring > 0)
		{
			in_substring = 0;
		}
		str++;
	}
	return (count);
}

static char	**ft_free_function(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free (s[i]);
		i++;
	}
	free (s);
	return (0);
}

static char	**ft_filling_substr(char **split_res, char const *s, char c)
{
	size_t	start;
	size_t	len;
	size_t	j;
	size_t	poll;

	start = 0;
	j = 0;
	poll = ft_substr_poll(s, c);
	while (s[start] != '\0' && j < poll)
	{
		while (s[start] == c && s[start] != '\0')
			start++;
		len = start;
		while (s[len] != c && s[len] != '\0')
			len++;
		split_res[j] = ft_substr(s, start, (len - start));
		if (!split_res[j])
			return (ft_free_function(split_res));
		j++;
		start = len;
	}
	split_res[j++] = NULL;
	return (split_res);
}

char	**ft_split(char const *s, char c)
{
	char	**split_res;

	split_res = (char **)ft_calloc((ft_substr_poll(s, c) + 1), sizeof(char *));
	if (!split_res)
		return (0);
	split_res = ft_filling_substr(split_res, s, c);
	return (split_res);
}
