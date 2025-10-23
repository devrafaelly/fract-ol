/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:06:03 by marvin            #+#    #+#             */
/*   Updated: 2025/10/17 16:06:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	malloc_error(void)
{
	ft_putstr_fd("Error: unable to allocate memory", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

static void	data_init(t_fractal *fractal)
{
	fractal->escape_value = 4;
	fractal->definition = 100;
	fractal->zoom = 1.0;
}

static void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->win, KeyPress,
		KeyPressMask, key_handler, fractal);
	mlx_hook(fractal->win, ButtonPress,
		ButtonPressMask, mouse_handler, fractal);
	mlx_hook(fractal->win, DestroyNotify,
		SubstructureNotifyMask, close_handler, fractal);
}

static void	get_img_addr(t_fractal *fractal)
{
	fractal->img->pixel_ptr = mlx_get_data_addr(fractal->img->img_ptr,
			&fractal->img->bpp,
			&fractal->img->width_bytes,
			&fractal->img->endian);
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
		malloc_error();
	fractal->win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, fractal->name);
	if (!fractal->win)
	{
		clean_up(fractal);
		malloc_error();
	}
	fractal->img = ft_calloc(1, sizeof(t_img_data));
	if (!fractal->img)
	{
		clean_up(fractal);
		malloc_error();
	}
	fractal->img->img_ptr = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (!fractal->img->img_ptr)
	{
		clean_up(fractal);
		malloc_error();
	}
	get_img_addr(fractal);
	data_init(fractal);
	events_init(fractal);
}
