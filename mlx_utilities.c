/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utilities.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 20:32:50 by oadewumi          #+#    #+#             */
/*   Updated: 2024/07/03 21:55:42 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//(m->x_max - m->x_min) is the total width of the current view in the 
// fractal space.
// *****
// (m->y_max - m->y_min) is the total height of the current view in the 
// fractal space.
// *****
// Dividing by 6: Reduces the current range to a smaller step size. This step 
// size determines the portion of the current range to set the boundaries by.
// using values < 6 will result in larger & more pronounced zoom-in steps while
// using values > 6 will result in a small & gradual zoom-in steps.
// *****
// Dividing by 2: Further refines the step size to determine how much to move
// the boundaries inward.
// using values < 2 will make the zoom-in effect more aggressive while
// using values > 2 will make the zoom-in effect smoother (why not :D).
// *****
// Thus the effect is a balance between zoom level & view movement: 
// The combo of dividing by 6 & then 2 provides a specific zooming effect:
// Not too fast: Ensures the zooming effect is smooth and not too aggressive.
// Not too slow: Keeps the zooming effect noticeable without requiring too 
// many steps to achieve significant zooming.
void    zoom_in(t_draw *draw)
{
    double  x_range;
    double  y_range;

    x_range = (draw->x_max - draw->x_min) / 6;
    y_range = (draw->y_max - draw->y_min) / 6;
    draw->x_min = draw->x_min + (x_range / 2);
    draw->x_max = draw->x_max - (x_range / 2);
    draw->y_min = draw->y_min + (y_range / 2);
    draw->y_max = draw->y_max - (y_range / 2);
}

void    zoom_out(t_draw *draw)
{
    double  x_range;
    double  y_range;

    x_range = (draw->x_max - draw->x_min) / 6;
    y_range = (draw->y_max - draw->y_min) / 6;
    draw->x_min = draw->x_min - (x_range * 2);
    draw->x_max = draw->x_max + (x_range * 2);
    draw->y_min = draw->y_min - (y_range * 2);
    draw->y_max = draw->y_max + (y_range * 2); 
}

void	ft_key_hook(mlx_key_data_t keydata, void *param)
{
	// continue 030724
}

void    ft_scroll_hook(double xdelta, double ydelta, void *param)
{
    t_draw  *draw;
     
    draw = (t_draw *)param;
    (void)xdelta;
    if (ydelta > 0)
        zoom_in(draw);
    else if (ydelta < 0)
		zoom_out(draw);
	pix_rend(draw);// figure out what works: pix_rend(*draw)
}