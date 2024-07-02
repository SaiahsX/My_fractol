/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:06:15 by oadewumi          #+#    #+#             */
/*   Updated: 2023/12/13 11:37:49 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	This function adds a new node (t_list *new)	to the begining of the list 
that t_list **lst is pointing to	*/
/*	To do this, I understood that node 'new' will have its next (refernce)
pointed or equated to the dereferenced (**lst), so to *lst. 	*/
/*	However, we need to put some conditions in place:
.	If there is lst, then run the function and put 'new' in front of 'lst'.
.	If lst does not exist, then 'new' will be the lst.	*/
/*	Since its a void function. it has no return value.	*/

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst)
		new -> next = *lst;
	*lst = new;
}
