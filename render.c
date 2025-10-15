#include "fractol.h"

static int get_color(int iterations, int max_iter)
{
    int t;
    
    t = (iterations * 255) / max_iter;
    
    if (t < 32)
        return FRACTAL_PEACH;
    else if (t < 64)
        return FRACTAL_ROSE;
    else if (t < 96)
        return FRACTAL_PINK;
    else if (t < 128)
        return FRACTAL_MAGENTA;
    else if (t < 160)
        return FRACTAL_ORANGE;
    else if (t < 192)
        return FRACTAL_YELLOW;
    else if (t < 224)
        return FRACTAL_LIME;
    else
        return FRACTAL_WHITE;
}

static int put_pixel(t_img *img, int x, int y, int color)
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
    c.x = (map(x, -2.5, 1.0, WIDTH) * fractal->zoom) + fractal->shift_x;
    c.y = (map(y, 1.25, -1.25, HEIGHT) * fractal->zoom) + fractal->shift_y;
    if (!ft_strncmp(fractal->name, "julia", 5))
        set_julia(fractal, &z, &c);
    i = 0;
    while (i < fractal->definition)
    {
        z = sum_complex(square_complex(z), c);
        if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
        {
            color = get_color(i, fractal->definition);
            put_pixel(&fractal->img, x, y, color);
            return ;
        }
        i++;
    }
    put_pixel(&fractal->img, x, y, RETRO_BLACK);
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
    mlx_put_image_to_window(fractal, fractal->win, fractal->img.img_ptr, 0, 0);
}