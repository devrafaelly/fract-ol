#include "fractol.h"

int mandelbrot()
{

}

void    cleanup(t_fractal *fractal)
{
    if (fractal->img)
        mlx_destroy_image(fractal->mlx, fractal->img);
    if (fractal->win)
        mlx_destroy_window(fractal->mlx, fractal->win);
    mlx_destroy_display(fractal->mlx);
    free (fractal->mlx);
    fractal->mlx = NULL;
}

int put_pixel(int x, int y, int color)
{
    int offset;

    offset = (img->"pixel->bytes" * y) + (x * (img->bpp / 8));
}


int main(int ac, char **av)
{
    t_fractal  fractal;

    if (2 == ac && !ft_strncmp(av[1], "mandelbrot", 10) 
        || 4 == ac && !ft_strncmp(av[1], "julia", 5))
    {
        fractal.name = av[1];
        fractal_init(&fractal);
        fractal_render(&fractal)
        mlx_loop(fractal.mlx);
        return (0);
    }
    else
    {
        ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
        exit(EXIT_FAILURE);
    }
}
