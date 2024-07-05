/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:18:49 by oadewumi          #+#    #+#             */
/*   Updated: 2024/07/05 16:22:09 by oadewumi         ###   ########.fr       */
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

static unsigned int	calc_colour(int iteration)
{
	unsigned int	colour;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	double			iter_ratio;

	if (iteration < MAX_LOOPING)
	{
		iter_ratio = (double)iteration / MAX_LOOPING;
		r = (unsigned char)(255 * (1 - iter_ratio) * iter_ratio);
		g = (unsigned char)(255 * (1 - iter_ratio));
		b = (unsigned char)(255 * iter_ratio);
		colour = (r << 6) | (g << 8) | b;
	}
	else
		colour = 0xE6E6FA;
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
	t_draw	draw;

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
