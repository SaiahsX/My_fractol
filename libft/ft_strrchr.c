/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:39:28 by oadewumi          #+#    #+#             */
/*   Updated: 2023/12/13 11:41:06 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This function is similar to ft_strchr, except 
it locates the last occurence of 'c' in the string pointed to by 'str'*/
/* The return value is the pointer to the 
address of the last occurence of 'c' and
 everything afterwards is also printed*/
/* In this function, i used the behaviour of ft_strlen 
to count to the end of the string and searched backwards*/
/*	The condition of search is modified from str[count] >= 0 to 
count >= 0, since this is logical and would terminate when the count 
reaches 0.	*/
/* This function imitates the standard C library funtion strrchr*/

char	*ft_strrchr(const char *str, int c)
{
	unsigned char	x;
	int				count;

	x = c;
	count = 0;
	while (str[count])
	{
		count++;
	}
	while (count >= 0)
	{
		if (str[count] == x)
			return ((char *)str + count);
		count--;
	}
	return (0);
}
