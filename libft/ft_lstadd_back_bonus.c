/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:18:18 by oadewumi          #+#    #+#             */
/*   Updated: 2023/12/13 11:37:42 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	This function adds a new node (t_list *new)	to the end of the list 
that t_list **lst is pointing to.	*/
/*	To do this, I understood that moving from the first node to the next could 
lead to losing the head (first node), hence, we create a new t_list *extra to 
hold the position and content of dereferenced (**lst), so to *lst. 	*/
/*	However, we need to put some conditions in place:
.	If *lst is NULL, then *lst is equal 'new'. and the program returns (ends).
.	If new exists, then run the function in a loop with 'extra' as the new head
pointing to the next node until the last node. Then equate the last node ref
to 'new'.	*/
/*	Since its a void function. it has no return value.	*/

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*extra;

	extra = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	if (new)
	{
		while (extra -> next != NULL)
		{
			extra = extra -> next;
		}
		extra -> next = new;
	}
}
