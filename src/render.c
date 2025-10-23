/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:09:41 by marvin            #+#    #+#             */
/*   Updated: 2025/10/17 16:09:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	put_pixel(t_img_data *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->pixel_ptr + (y * img->width_bytes) + (x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}

static void	set_julia(t_fractal *fractal, int x, int y)
{
	t_complex	z;
	t_complex	c;
	int		color;
	int		i;

	z.x = (map(x, -2.0, 2.0, WIDTH) * fractal->zoom) + fractal->shift_x;
	z.y = (map(y, 2.0, -2.0, HEIGHT) * fractal->zoom) + fractal->shift_y;
	c.x = fractal.julia_x;
	c.y = fractal.julia_y;
	i = 0;
	while (i < fractal->definition)
	{
		z = sum_complex(square_complex(z, fractal->type), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = map(i, JULIA_PURPLE, JULIA_CIAN, fractal->definition);
			put_pixel(fractal->img, x, y, color);
			return ;
		}
		i++;
	}
	put_pixel(fractal->img, x, y, BLACK);
}

static void	set_mandel(t_fractal *fractal, int x, int y)
{
	t_complex	z;
	t_complex	c;
	int		color;
	int		i;

	z.x = 0.0;
	z.y = 0.0;
	c.x = (map(x, -2.0, 2.0, WIDTH) * fractal->zoom) + fractal->shift_x;
	c.y = (map(y, 2.0, -2.0, HEIGHT) * fractal->zoom) + fractal->shift_y;
	i = 0;
	while (i < fractal->definition)
	{
		z = sum_complex(square_complex(z, fractal->type), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = map(i, MANDEL_BLUE, MANDEL_GOLD, fractal->definition);
			put_pixel(fractal->img, x, y, color);
			return ;
		}
		i++;
	}
	put_pixel(fractal->img, x, y, BLACK);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			switch(fractal->type)
			{
			case MANDELBROT:
				set_mandel(fractal, x, y);
				break;
			case JULIA:
				set_julia(fractal, x, y);
				break;
			}
		}
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img->img_ptr, 0, 0);
}
