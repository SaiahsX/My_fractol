/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   security_utilities.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:44:32 by oadewumi          #+#    #+#             */
/*   Updated: 2024/07/05 16:49:03 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//This error message utilises the ft_putendl from my Libft, it 
//prints out a string followed by a new line. Also, this function
//is made to print out "Error: "as a prefix to all received strings.
//the file descriptor used is 2, (written to standard error output).
void	error_message(char *str, char *txt)
{
	ssize_t	msg;

	msg = write(2, "Error: ", 7);
	if (msg == -1)
	{
		error_message("error write malfunction", 0);
	}
	if (str)
		ft_putendl_fd(str, 2);
	if (txt)
		ft_putendl_fd(txt, 2);
	exit(EXIT_FAILURE);
}

//utilising the perror function with EINVAL error code
// Sets errno to an appropriate error code
void	set_and_perror(const char *msg)
{
	errno = EINVAL;
	perror(msg);
	exit (EXIT_FAILURE);
}

//This function is used to specifically exit on error in a clean way if 
//draw.img fails. 
//This function call mlx_terminate which is prebuilt function in the
//MLX42 library.
//Then my own error handling function is called to exit safely.
void	draw_error(mlx_t *mlx)
{
	mlx_terminate(mlx);
	set_and_perror("draw.img failed to execute!");
}
