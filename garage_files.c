/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garage_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:54:07 by oadewumi          #+#    #+#             */
/*   Updated: 2024/07/01 16:54:31 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//This is a modified string comare function from my libft without the size
//limitation for comparison. The return value return the difference between
//the two string. if the strings are identical, it returns 0 else it returns 
// the difference to let us know they are a not identical.

/* int	ft_strcmp(const char *src, const char *dest)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && dest[i] != '\0')
	{
		if (src[i] != dest[i])
			return ((unsigned char) src[i] - (unsigned char) dest[i]);
		i++;
	}
	return ((unsigned char) src[i] - (unsigned char) dest[i]);
}
*/

