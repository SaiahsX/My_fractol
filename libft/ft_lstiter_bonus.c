/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:42:01 by oadewumi          #+#    #+#             */
/*   Updated: 2023/12/13 11:38:10 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	The ft_lstiter function iterates through each node of the linked list and 
applies the given function f to the content of each node.	*/
/*	It checks for valid inputs (both the list pointer and the function pointer)
before proceeding to avoid unexpected behavior or crashes.	*/
/*	This function is useful when there's a need to perform a specific 
operation or function on the content of each node in the linked list without 
explicitly iterating through the list in the main code.	*/

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
