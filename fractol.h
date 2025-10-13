#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "mlx/mlx.h"

//# include <mlx.h>
# include <stdlib.h>
# include <unistd.h> 
# include <math.h> 

# define ERROR_MESSAGE "Error: invalid input\n\tUsage: ./fractol mandelbrot\n\tUsage: ./fractol julia [param1] [param2]\n"

# define WIDTH 800
# define HEIGHT 800

typedef struct s_fractal
{
    // mlx
    char    *name;
    void    *mlx;
    void    *win;
    t_img   *img;
    // hooks
}   t_fractal;

typedef struct s_img
{
    void *img_ptr;
    char *pixel_ptr;
    int bbp;
    int size_len;
    int endian;
    int width_bits;
}   t_img;

typedef struct s_complex
{
    double x;
    double y;
}   t_complex;

int fractal_init(t_fractal *fractal);
void    fractal_render(t_fractal *fractal);

double  map(double unscaled_num, double new_min, double new_max, double old_max);
t_complex   square_complex(t_complex z);
t_complex   sum_complex(t_complex z, t_complex c);

void    cleanup(t_fractal *fractal);

#endif