/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:27:59 by oadewumi          #+#    #+#             */
/*   Updated: 2023/12/13 11:38:47 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	This function, unlike normal strlen function, we do not have an index 
counter but we just have an int counter variable log called 'count'.	*/
/*	The first thing we want to check for is if there is no lst.
-	this should return an integer zero.	*/
/*	The next step is a loop to count condition, while the next refernce
is not equal to NULL.
-	This should loop and count the number it goes into the loop until
	it encounters NULL in the next reference.	*/
/*	The return int value is 'count'	*/

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 1;
	if (!lst)
		return (0);
	while (lst -> next != NULL)
	{
		lst = lst -> next;
		count++;
	}
	return (count);
}
