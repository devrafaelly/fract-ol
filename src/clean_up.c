/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 19:16:48 by rafaoliv          #+#    #+#             */
/*   Updated: 2025/10/17 16:07:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	clean_up(t_fractal *fractal)
{
	if (fractal->img->img_ptr)
		mlx_destroy_image(fractal->mlx, fractal->img->img_ptr);
	if (fractal->img)
	{
		free(fractal->img);
		fractal->img = NULL;
	}
	if (fractal->win)
		mlx_destroy_window(fractal->mlx, fractal->win);
	mlx_destroy_display(fractal->mlx);
	free (fractal->mlx);
	fractal->mlx = NULL;
}
