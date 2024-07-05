/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:52:35 by oadewumi          #+#    #+#             */
/*   Updated: 2024/07/05 17:08:20 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(double x, double y, double cmplx_x, double cmplx_y)
{
	double	real;
	double	fake;
	int		i;
	double	temp;

	real = x;
	fake = -y;
	i = 0;
	while (i < MAX_LOOPING && ((real * real) + (fake * fake)) < 4.0)
	{
		temp = (real * real) - (fake * fake) + cmplx_x;
		fake = 2.0 * real * fake + cmplx_y;
		real = temp;
		i ++;
	}
	return (i);
}

int	mandelbrot(double x, double y)
{
	double	real;
	double	fake;
	int		i;
	double	temp;

	i = 0;
	real = 0.0;
	fake = 0.0;
	while (i < MAX_LOOPING && ((real * real) + (fake * fake)) < 4.0)
	{
		temp = (real * real) - (fake * fake) + x;
		fake = 2.0 * real * fake + y;
		real = temp;
		i ++;
	}
	return (i);
}
