#include "fractol.h"

static void    malloc_error(void)
{
    ft_putstr_fd("Error: unable to allocate memory", STDERR_FILENO);
    exit(EXIT_FAILURE);
}

void    fractal_init(t_fractal *fractal)
{
    fractal->mlx = mlx_init();
    if (!fractal->mlx)
        malloc_error();
    fractal->win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, fractol->name);
    if(!fractal->win)
    {
        cleanup(fractal);
        malloc_error();
    }
    fractal->img.img_ptr = mlx_new_image(fractal->mlx, WIDTH, HEIGHT)
    if(!fractal->img.img_ptr)
    {
        cleanup(fractal);
        malloc_error();
    }
    fractal->img.pixel_ptr = mlx_get_data_addr(fractal->img.img_ptr,
                                                &fractal->img.bpp,
                                                &fractal->img.size_len,
                                                &fractal->img.endian);
    events_init(fractal);
    data_init(fractal);
}
