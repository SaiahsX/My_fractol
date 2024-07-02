/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:18:49 by oadewumi          #+#    #+#             */
/*   Updated: 2024/07/02 14:24:57 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


t_draw	mlx_init_settings(char *argv[], t_draw *draw)
{    
	draw->x_min = -3;
	draw->x_max = 3;
	draw->y_min = -3;
	draw->y_max = 3;
	if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
		draw->type = 'm';
	else if (ft_strncmp(argv[1], "julia", 5) == 0)
	{
		draw->type = 'j';
		draw->cmplx_x = ft_atod(argv[2]);
		draw->cmplx_y = ft_atod(argv[3]);
	}
	return (*draw); //check this for correction
}







int main(int ac, char *av[])
{
    t_draw  draw;
    
    validate_input(ac, av);
    mlx_init_settings(av, &draw);
	draw.mlx = mlx_init(WIDTH, HEIGHT, "fractol", false);
	if (!draw.mlx)
		set_and_perror("draw.mlx failed!");
	draw.img = mlx_new_image(draw.mlx, WIDTH, HEIGHT);
	if (!draw.img)
		set_and_perror("draw.img failed to execute!")
	render


	// || mlx_image_to_window(draw.mlx,draw.img, 0, 0))
    
    return (0);
}