#include "fractol.h"

static void handle_pixel(t_fractal *fractal, int x, int y)
{
    t_complex   z;
    t_complex   c;
    double temp_x;
    int i;

    z.x = 0.0;
    z.y = 0.0;
    c.x = map(x, -2.5, 1.0, WIDTH - 1);
    c.y = map(y, 1.25, -1.25, HEIGHT - 1);
    i = 0;
    while (????)
    {
        z = sum_complex(square_complex(z), c);
        if (??)
        {
            pixel_put()
            return ;
        }
    }
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
}