/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:51:17 by oadewumi          #+#    #+#             */
/*   Updated: 2023/12/13 11:40:26 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	This function copies src & apppends it at end of dst (concactenation)	*/
/*	The result is then null terminated.	*/
/*	The logic of this function is to do ft_strlen on 'src' & 'dst'....	*/
/*	Also, we need to calculate the remaining space left by the dstsize
for src to occupy, hence, 'space_for_src = dstsize - dstlen - 1', 
this we will set as a limiter for the function.	*/
/*	In this function, I began to utilise my premade function ft_strlen. 	*/
/*	Also I began to use my header file 'libft.h'	*/
/*	Added a condition if both dst and dstsize are 0, it return src lenght	*/
/*	Also added + 1 to the condition if dstlen + 1 > dstsize.	*/
/*	In this function, the return values vary in the sense that if the 
if the dstlen is larger than dstsize, we get the sum of dstsize & srclen 
as return values and nothing from source is copied as a result.	*/
/*	Otherwise, we get the sum of the dstlen & srclen and some copied string	*/
/*	This function imitates the behaviour of the standard Clibrary function 
strlcat	*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	src_i;
	size_t	space_for_src;

	src_i = 0;
	if (!dst && !dstsize)
		return (ft_strlen(src));
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstlen + 1 > dstsize)
		return (dstsize + srclen);
	space_for_src = dstsize - dstlen - 1;
	while (src[src_i] != '\0' && src_i < space_for_src)
	{
		dst[dstlen + src_i] = src[src_i];
		src_i++;
	}
	dst[dstlen + src_i] = '\0';
	return (dstlen + srclen);
}
