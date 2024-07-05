/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:20:10 by oadewumi          #+#    #+#             */
/*   Updated: 2024/07/05 18:29:06 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <errno.h>
# include <stdlib.h>
# include "./MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include "libft/libft.h"

# define WIDTH 700
# define HEIGHT 700
# define MAX_LOOPING 1000

typedef struct s_draw
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	double		x_min;
	double		x_max;
	double		y_min;
	double		y_max;
	char		type;
	uint32_t	x;
	uint32_t	y;
	double		cmplx_x;
	double		cmplx_y;
}	t_draw;

void	validate_input(int argc, char *argv[]);
void	mlx_init_settings(char *argv[], t_draw *draw);
void	pix_rend(t_draw *draw);
void	pix_rend_help(t_draw *draw);
int		julia(double x, double y, double cmplx_x, double cmplx_y);
int		mandelbrot(double x, double y);
void	ft_scroll_hook(double xdelta, double ydelta, void *param);
void	ft_key_hook(mlx_key_data_t keydata, void *param);
void	zoom_in(t_draw *draw);
void	zoom_out(t_draw *draw);

//utilities
double	ft_atod(char *str);

//error handling
void	set_and_perror(const char *msg);
void	draw_error(mlx_t *mlx);
void	error_message(char *str, char *txt);

#endif