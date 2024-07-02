/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:30:44 by oadewumi          #+#    #+#             */
/*   Updated: 2023/12/13 11:40:39 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This function counts the number of characters 
pointed to by the string 'str' and returns an integer value 'count'*/
/*	Modification on the variable type was done from 'char' to 'const char'.
This is in line with the manual prototype.	*/
/* This function imitates the standard C libraray function 'strlen'*/

int	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}
