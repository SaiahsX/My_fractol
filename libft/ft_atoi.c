/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:14:27 by oadewumi          #+#    #+#             */
/*   Updated: 2024/06/14 13:14:11 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	This function is almost the same as the piscine Atoi, but
1:	This checks for and skips over whitespaces.
2:	This checks for only one sign (polarity) especially '-', it takes 
account of it and skips it but if it encounters 2 '-' signs,
 it returns a zero.
3:	This starts to check the digits and converts them to int.	*/
/*	This function was made to use the size_t variable to accomodate for 
large numbers.	*/
/*	This function also made use FT_LONG_MAX (which was define in my header)	*/
/*	using the 'if' condition was to handle possible overflows  from large
or special range of numbers eg."63410682753376583680" .	*/
/*	Due to the long lenght of my original work, thei function was
split into two. A static int function (this stays only in this file)
is used to calculate the output & it is fed back to the main function.	*/
/*	This function imitates the behaviour of the standard c function Atoi	*/

#include "libft.h"

static int	ft_ret_output(const char *str, int polarity)
{
	size_t	output;
	int		indx;

	output = 0;
	indx = 0;
	while (ft_isdigit(str[indx]))
	{
		if (output > FT_LONG_MAX / 10
			|| (output == FT_LONG_MAX / 10 && str[indx] > FT_LONG_MAX % 10))
		{
			if (polarity > 0)
				return (-1);
			else
				return (0);
		}
		output = output * 10 + (str[indx] - '0');
		indx++;
	}
	return (output);
}

int	ft_atoi(const char *str)
{
	size_t	output;
	int		indx;
	int		polarity;

	output = 0;
	indx = 0;
	polarity = 1;
	while (str[indx] == 32 || (str[indx] >= 9 && str[indx] <= 13))
		indx++;
	if (str[indx] == '-' || str[indx] == '+')
	{
		if (str[indx] == '-')
			polarity *= -1;
		indx++;
	}
	output = ft_ret_output(str + indx, polarity);
	return (output * polarity);
}
