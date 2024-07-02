/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:53:04 by oadewumi          #+#    #+#             */
/*   Updated: 2023/12/13 11:31:24 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The provided code contain implementations of several of my string 
manipulation functions such as ft_memcpy, ft_strlen, ft_bzero, ft_calloc, 
ft_strdup, ft_count_int, and ft_itoa.	*/

/*	Here's a breakdown of the functions:

1. ft_memcpy: Copies n bytes from the source memory area src to the destination 
memory area dst.

2. ft_strlen: Computes the length of a string by counting the number of 
characters until the null terminator '\0' is encountered.

3. ft_bzero: Sets the memory area pointed to by s to zero for a specified 
number of bytes n.

4. ft_calloc: Allocates memory for a specified number of elements of a 
specified size. It initializes the allocated memory with zeros.

5. ft_strdup: Duplicates a string s1 by allocating memory for it, copying the 
characters, and returning a new string.

6. ft_count_int: Counts the number of digits in an integer n.

7. ft_itoa: Converts an integer n into a string. It allocates memory for the 
string representation of the integer and handles both positive 
and negative integers.	*/

#include "libft.h"

static int	ft_count_int(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count++;
	}
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long	s;
	int		count;
	char	*str;

	s = n;
	if (n == 0)
		return (ft_strdup("0"));
	count = ft_count_int(n);
	str = (char *) ft_calloc(count + 1, sizeof(char));
	if (!str)
		return (0);
	if (s < 0)
	{
		s = -s;
		str[0] = '-';
	}
	while (s && count != 0)
	{
		str[count - 1] = (s % 10) + '0';
		s = s / 10;
		count--;
	}
	return (str);
}
