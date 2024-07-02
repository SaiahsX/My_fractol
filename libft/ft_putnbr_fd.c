/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:45:35 by oadewumi          #+#    #+#             */
/*   Updated: 2023/12/13 11:39:47 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	This function uses recursive method to convert integer values to ASCII 
character and print(write) it out.	*/
/*	In this function, the min int (-2147483648) was printed exclusively.	*/
/*	The preivious statment was no longer true and had to be replaced by
a new variable declaration, long nb, which will take care of the long min
long max edge cases or prevent an overflow.	*/
/*	Hence, every int n variable replaced with nb reflecting long variable	*/
/*	Else, This function takes care of every value 
up to max int (2147483647).	*/
/*	If there is a negative value, the '-' sign is printed out exclusively
because to iterate we use need to also convert the int to +ve for the 
recursion to write out the converted result	*/
/*	Recursion in the case works in a way that it splits the int via
division (/) & iterates to the first int digit which is then converted to 
ASCII xter, then prints & recursion works its way back up via use 
of % opertion for converting the next digit and prints until it gets
to the top. 	*/

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd(('-'), fd);
		nb *= -1;
	}
	if (nb < 10)
	{
		ft_putchar_fd((nb + '0'), fd);
	}
	if (nb >= 10)
	{
		ft_putnbr_fd((nb / 10), fd);
		nb = (nb % 10) + '0';
		ft_putchar_fd(nb, fd);
	}
}
