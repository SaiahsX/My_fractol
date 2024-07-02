/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:16:21 by oadewumi          #+#    #+#             */
/*   Updated: 2023/12/13 11:37:56 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	In this function, A double pointer is used to modify the original pointer 
to the list. Since the function is intended to clear the entire list and 
modify the pointer to an empty list, it needs to change the value of the 
original pointer passed to it, which requires a double pointer.	*/
/*	t_list **lst: Represents a pointer to a pointer to the first node of the 
linked list. It is a double pointer because the function will modify the 
original pointer to the list.
	void (*del)(void*): Is a function pointer that points to a function 
responsible for freeing the content of each node.	*/
/*	while (*lst) enters the loop until (*lst) becomes NULL (end of list).	*/
/*	It iterates through the list, frees the memory allocated for each node, 
deletes or frees the content of each node using the provided deletion function,
and updates the pointers accordingly.
Finally, it sets the original pointer to the list to NULL, indicating an 
empty list after clearing all its elements.	*/

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		if ((del))
			(del)((*lst)->content);
		free(*lst);
		(*lst) = temp;
	}
	(*lst) = NULL;
}
