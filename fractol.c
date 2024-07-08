/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:18:49 by oadewumi          #+#    #+#             */
/*   Updated: 2024/07/08 10:09:50 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mlx_init_settings(char *argv[], t_draw *draw)
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
}

// t = iteration ratio
// r = red, g = green, b = blue
static unsigned int	calc_colour(int iteration)
{
	unsigned int	colour;
	double			t;

	if (iteration < MAX_LOOPING)
	{
		t = (double)iteration / MAX_LOOPING;
		if (t < 0.2)
			colour = intrplt(t / 0.2, 0x000000FF, 0x0000FFFF);
		else if (t < 0.4)
			colour = intrplt((t - 0.2) / 0.2, 0x0000FFFF, 0x00FFFFFF);
		else if (t < 0.6)
			colour = intrplt((t - 0.4) / 0.2, 0x00FFFFFF, 0x00FF00FF);
		else if (t < 0.8)
			colour = intrplt((t - 0.6) / 0.2, 0x00FF00FF, 0xFFFF00FF);
		else
			colour = intrplt((t - 0.8) / 0.2, 0xFFFF00FF, 0xFF0000FF);
	}
	else
		colour = 0x000000;
	return (colour);
}

void	pix_rend_help(t_draw *draw)
{
	double			tmp_x;
	double			tmp_y;
	int				iteration;
	unsigned int	colour;

	tmp_x = draw->x_min + ((draw->x / (double)WIDTH)
			* (draw->x_max - draw->x_min));
	tmp_y = draw->y_min + ((draw->y / (double)HEIGHT)
			* (draw->y_max - draw->y_min));
	if (draw->type == 'j')
		iteration = julia(tmp_x, tmp_y, draw->cmplx_x, draw->cmplx_y);
	else
		iteration = mandelbrot(tmp_x, tmp_y);
	colour = calc_colour(iteration);
	mlx_put_pixel(draw->img, draw->x, draw->y, colour);
	draw->x++;
}

void	pix_rend(t_draw *draw)
{
	draw->y = 0;
	while (draw->y < HEIGHT)
	{
		draw->x = 0;
		while (draw->x < WIDTH)
		{
			pix_rend_help(draw);
		}
		draw->y++;
	}
}

int	main(int ac, char *av[])
{
	static t_draw	draw;

	validate_input (ac, av);
	mlx_init_settings(av, &draw);
	draw.mlx = mlx_init(WIDTH, HEIGHT, "fractol", false);
	if (!draw.mlx)
		set_and_perror("draw.mlx failed!");
	draw.img = mlx_new_image(draw.mlx, WIDTH, HEIGHT);
	if (!draw.img || mlx_image_to_window (draw.mlx, draw.img, 0, 0))
		draw_error(draw.mlx);
	pix_rend(&draw);
	mlx_scroll_hook(draw.mlx, &ft_scroll_hook, &draw);
	mlx_key_hook(draw.mlx, ft_key_hook, &draw);
	mlx_loop(draw.mlx);
	mlx_delete_image(draw.mlx, draw.img);
	mlx_terminate(draw.mlx);
	return (EXIT_SUCCESS);
}
