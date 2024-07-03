/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:20:10 by oadewumi          #+#    #+#             */
/*   Updated: 2024/07/03 21:56:11 by oadewumi         ###   ########.fr       */
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
# define MAX_LOOPING 500

// typedef struct s_draw
// {
// 	void		*window;
// 	void		*context;
// 	int32_t		width;
// 	int32_t		height;
// 	double		delta_time;
// }	t_draw;

// typedef void (*mlx_scrollfunc)(double xdelta, double ydelta, void* param);

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

void            ft_scroll_hook(double xdelta, double ydelta, void *param);
void    	ft_key_hook(mlx_key_data_t keydata, void *param);
void	        validate_input(int argc, char *argv[]);
void	        mlx_init_settings(char *argv[], t_draw *draw);
// int	    ft_strcmp(const char *src, const char *dest);
void 	pix_rend_help(t_draw *draw);
// unsigned int 	pix_rend_help(t_draw *draw);
void            pix_rend(t_draw *draw);
// unsigned int    pix_rend(t_draw *draw);
double          ft_atod(char *str);

//error handling
void	error_message(char *str, char *txt);
void    set_and_perror(const char *msg);
void	draw_error(mlx_t *mlx);

# endif