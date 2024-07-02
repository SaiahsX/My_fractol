/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:57:00 by oadewumi          #+#    #+#             */
/*   Updated: 2023/12/13 11:41:12 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	This function trims off the edged/sides of a string the characters
in a set and returns the remainder of the string as a new string.	*/
/*	The idea was to use two indexes, start and end.	*/
/*	'Start' will track the position of the pointer from the left of the
string after it has exhauseted the search of the 'set' characters.
while, 'end' will track from the right until the 'set' xters are found.	*/
/*	to prep the 'end' index, we need to get ft_strlen - 1 of the source.	*/
/*	with this we do not need to consider the null terminator introduced 
by ft_strlen function for this.	*/
/*	the next function used was ft_strchr to get the first occurence of a 
xter (here, the xter is each xter of the source) in the set. Then it
iterates until all the 'set' is found for both sides of the source.
Hence the term Trim. 	*/
/*	Memory is allocated to the receptacle char variable 'result' with
the count + 2  to cater far an extra needed xter and '\0' becauuse of
maths blah blah lol.	*/
/*	The result is the subtraction of the end pointer from the start
pointer + 2 to cater for the the extra xter & '\0' due to some maths blah
blah.	*/
/*	The return value is the ft_strlcpy to copy from the pointer to the 
current index start of the source upto the size specified in the malloc.	*/
/*	Update: Changed the variable type of start and en to long and 
setting the condition if either s1 or set are null to return 0	*/

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	long	start;
	long	end;

	if (!s1 || !set)
		return (0);
	start = 0;
	end = ft_strlen((char *)s1) - 1;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	result = (char *) malloc (end - start + 2);
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1 + start, (end - start + 2));
	return (result);
}
