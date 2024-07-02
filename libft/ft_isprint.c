/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:29:39 by oadewumi          #+#    #+#             */
/*   Updated: 2023/12/13 11:31:15 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	This function checks if the argument 'p' is a printable character
from the ASCII table,then it returns a value of 1 if that is true 
and 0 if that is false.	*/
/*	Updated my search range from octal to decimal from the ascii table.	*/
/* This fuction is to imitate the behaviour of the 
standard C library function 'isalnum'*/

int	ft_isprint(int p)
{
	if (p >= 32 && p <= 126)
	{
		return (1);
	}
	return (0);
}
