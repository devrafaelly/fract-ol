/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaoliv <rafaoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:01:28 by rafaoliv          #+#    #+#             */
/*   Updated: 2025/10/16 19:08:00 by rafaoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void put_pixel(t_img_data *img, int x, int y, int color)
{
    char *pixel;

    pixel = img->pixel_ptr + (y * img->width_bytes) + (x * (img->bpp / 8));
    *(unsigned int *)pixel = color;
}

static void set_julia(t_fractal *fractal, t_complex *z, t_complex *c)
{
        z->x = c->x;
        z->y = c->y;
        c->x = fractal->julia_x;
        c->y = fractal->julia_y;
}

static void handle_pixel(t_fractal *fractal, int x, int y)
{
    t_complex   z;
    t_complex   c;
    int color;
    int i;

    z.x = 0.0;
    z.y = 0.0;
    c.x = (map(x, -2.0, 2.0, WIDTH) * fractal->zoom) + fractal->shift_x;
    c.y = (map(y, 2.0, -2.0, HEIGHT) * fractal->zoom) + fractal->shift_y;
    if (!ft_strncmp(fractal->name, "julia", 5))
        set_julia(fractal, &z, &c);
    i = 0;
    while (i < fractal->definition)
    {
        z = sum_complex(square_complex(z), c);
        if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
        {
            color = map(i, FRACTAL_ROSE, FRACTAL_MINT, fractal->definition);
            put_pixel(fractal->img, x, y, color);
            return ;
        }
        i++;
    }
    put_pixel(fractal->img, x, y, FRACTAL_BLACK);
}

void    fractal_render(t_fractal *fractal)
{
    int x;
    int y;

    y = -1;
    while (++y < HEIGHT)
    {
        x = -1;
        while (++x < WIDTH)
        {
            handle_pixel(fractal, x, y);
        }
    }
    mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img->img_ptr, 0, 0);
}
