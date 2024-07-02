/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:06:30 by oadewumi          #+#    #+#             */
/*   Updated: 2023/12/13 11:38:39 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	This function is about creating a new node for a linked list.	
	Linked list consist of nodes where each node contains 2 parts:
	The data itself & a refrnce (or pointer) to the next node in the sequence.
	This way, the elements in a linked list are not necessarily stored in 
	contigous memory locations, unlike arrays. Instead, 
	they are connected via pointers.
	The first node in a llinked list is called the Head & the last node 
	typically pointss to NULL, indicating the end of the list.
	`void *content`: A pointer to the content that will be stored 
	in the new node.
	`t_list *`: A pointer to the newly created node. 
	If memory allocation fails, it returns `NULL`	*/

/*	Description:
- The function allocates memory for a new_node using `malloc`.
- Assigns the given `content` to the `content` field of the new node.
- Sets the `next` pointer of the new node to `NULL`.
- Returns a pointer to the newly created node. If memory allocation fails,
it returns `NULL`.	*/

/*	'new_node -> content' can also be written as (*new_node).content	*/

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc (sizeof(t_list));
	if (!new_node)
		return (0);
	new_node -> content = content;
	new_node -> next = NULL;
	return (new_node);
}
