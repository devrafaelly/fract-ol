/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_colors_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 19:46:36 by marvin            #+#    #+#             */
/*   Updated: 2025/10/17 19:46:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	get_color(t_fractal *fractal)
{
	if (fractal->color_scheme == SCHEME_1)
	{
		fractal->color_start = MANDEL_BLUE;
		fractal->color_end = MANDEL_GOLD;
	}
	else if (fractal->color_scheme == SCHEME_2)
	{
		fractal->color_start = JULIA_PURPLE;
		fractal->color_end = JULIA_CIAN;
	}
	else if (fractal->color_scheme == SCHEME_3)
	{
		fractal->color_start = SHIP_BLUE;
		fractal->color_end = SHIP_ORANGE;
	}
	else if (fractal->color_scheme == SCHEME_4)
	{
		fractal->color_start = SAF_RED;
		fractal->color_end = SAF_PINK;
	}
}

void	put_color(t_fractal *fractal, int i, int x, int y)
{
	int	color;

	get_color(fractal);
	color = map(i, fractal->color_start, fractal->color_end, fractal->definition);
	put_pixel(fractal->img, x, y, color);
}
