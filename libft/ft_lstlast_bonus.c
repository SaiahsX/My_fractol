/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:05:29 by oadewumi          #+#    #+#             */
/*   Updated: 2023/12/13 11:38:25 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	This function returns the the last node of the list.	*/
/*	To begin, we need to check if there is no list, then return NUll.	*/
/*	We need to iterate/loop through the list whith the condition;
while lst->next!= NULL	*/
/*	lst will be equal to the reference of the prior lst until NULL.	*/

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next != NULL)
	{
		lst = lst -> next;
	}
	return (lst);
}
