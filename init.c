#include "fractol.h"

static void    malloc_error(void)
{
    ft_putstr_fd("Error: unable to allocate memory", STDERR_FILENO);
    exit(EXIT_FAILURE);
}

void    clean_up(t_fractal *fractal)
{
    if (fractal->img)
        mlx_destroy_image(fractal->mlx, fractal->img);
    if (fractal->win)
        mlx_destroy_window(fractal->mlx, fractal->win);
    mlx_destroy_display(fractal->mlx);
    free (fractal->mlx);
    fractal->mlx = NULL;
}

static void    data_init(t_fractal *fractal)
{
    fractal->escape_value = 4;
    fractal->definition = 100;
    fractal->shift_x = 0.0;
    fractal->shift_y = 0.0;
    fractal->zoom = 1.0;
}

static void    events_init(t_fractal *fractal)
{
    mlx_hook(fractal->win, KetPress,
            KetPressMask, key_handler, fractal);
    mlx_hook(fractal->win, ButtonPress,
            ButtonPressMask, mouse_handler, fractal);
    mlx_hook(fractal->win, DestroyNotify,
            SubstructureNotifyMask, close_handler, fractal);
    mlx_hook(fractal->win, MotionNotify,
            PointerMotionMask, julia_track, fractal);
}

void    fractal_init(t_fractal *fractal)
{
    fractal->mlx = mlx_init();
    if (!fractal->mlx)
        malloc_error();
    fractal->win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, fractol->name);
    if(!fractal->win)
    {
        clean_up(fractal);
        malloc_error();
    }
    fractal->img.img_ptr = mlx_new_image(fractal->mlx, WIDTH, HEIGHT)
    if(!fractal->img.img_ptr)
    {
        clean_up(fractal);
        malloc_error();
    }
    fractal->img.pixel_ptr = mlx_get_data_addr(fractal->img.img_ptr,
                                                &fractal->img.bpp,
                                                &fractal->img.width_bytes,
                                                &fractal->img.endian);
    events_init(fractal);
    data_init(fractal);
}
