/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:12:40 by oadewumi          #+#    #+#             */
/*   Updated: 2023/12/13 11:30:55 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*This function checks that the returned 
character to the argument 'alf' is an alphabet*/
/* It returns 1 if it is true and 0 if its false */
/* This function imitates the standard Clibrary function 'isalpha' */

int	ft_isalpha(int alf)

{
	if ((alf >= 'A' && alf <= 'Z') || (alf >= 'a' && alf <= 'z'))
	{
		return (1);
	}
	return (0);
}
