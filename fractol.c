/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:18:49 by oadewumi          #+#    #+#             */
/*   Updated: 2024/07/03 21:51:04 by oadewumi         ###   ########.fr       */
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


/* unsigned int	pix_rend_help(t_draw *draw)
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
	draw->x++;
	return (colour);
}*/

void	pix_rend(t_draw *draw)
{
	unsigned int	colour;
	
	colour = 0;
	draw->y = 0;
	while(draw->y < HEIGHT)
	{
		draw->x = 0;
		while (draw->x < WIDTH)
		{
			pix_rend_help(draw);
		}
		draw->y++;
	}
	return (colour);
}

/* unsigned int	pix_rend(t_draw *draw)
{
	unsigned int	colour;
	
	colour = 0;
	draw->y = 0;
	while(draw->y < HEIGHT)
	{
		draw->x = 0;
		while (draw->x < WIDTH)
		{
		colour = pix_rend_help(draw);
		}
		draw->y++;
	}
	return (colour);
} */

int main(int ac, char *av[])
{
    t_draw  draw;
    
    validate_input(ac, av);
    mlx_init_settings(av, &draw);
	draw.mlx = mlx_init(WIDTH, HEIGHT, "fractol", false);
	if (!draw.mlx)
		set_and_perror("draw.mlx failed!");
	draw.img = mlx_new_image(draw.mlx, WIDTH, HEIGHT);
	if (!draw.img || mlx_image_to_window(draw.mlx,draw.img, 0, 0))
		draw_error(draw.mlx);
	pix_rend(&draw);
	mlx_scroll_hook(draw.mlx, &ft_scroll_hook, &draw);
	mlx_key_hook(draw.mlx, ft_key_hook, &draw);

    return (0);
}
