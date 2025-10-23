/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:57:54 by marvin            #+#    #+#             */
/*   Updated: 2025/10/17 15:57:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	reset_fractal(t_fractal *fractal)
{
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
}

int	close_handler(t_fractal *fractal)
{
	clean_up(fractal);
	exit(EXIT_SUCCESS);
}

int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_handler(fractal);
	else if (keysym == XK_Left 
			|| keysym == XK_A || keysym == XK_a)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysym == XK_Right
			|| keysym == XK_D || keysym == XK_d)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == XK_Up
			|| keysym == XK_W || keysym == XK_w)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysym == XK_Down
			|| keysym == XK_S || keysym == XK_s)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysym == 0x3d || keysym == 0xffab)
		fractal->definition += 10;
	else if (keysym == XK_minus)
		fractal->definition -= 10;
	else if (keysym == XK_r || keysym == XK_R)
		reset_fractal(fractal);
	else if (keysym == XK_c || keysym == XK_C)
		fractal->scheme = (fractal->scheme + 1) % SCHEME_TOTAL;
	fractal_render(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	double	zoom_ratio;

	if (fractal->type == SHIP)
	{
		x = map(x, -2.0, 1.0, WIDTH);
		y = map(y, 1.0, -2.0, HEIGHT);
	}
	else
	{
		x = map(x, -2.0, 2.0, WIDTH);
		y = map(y, 2.0, -2.0, HEIGHT);
	}
	if (button == Button5)
		zoom_ratio = 1.05;
	else if (button == Button4)
		zoom_ratio = 0.95;
	fractal->shift_x = x - (x - fractal->shift_x) * zoom_ratio;
	fractal->shift_y = y - (y - fractal->shift_y) * zoom_ratio;
	fractal->zoom *= zoom_ratio;
	fractal_render(fractal);
	return (0);
}
