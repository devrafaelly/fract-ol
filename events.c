#include "fractol.h"

int    close_handler(t_fractal *fractal)
{
    clean_up(fractal);
    exit(EXIT_SUCCESS);
}

int    key_handler(int keysym, t_fractal *fractal)
{
    if (keysym == XK_Escape)
        close_handler(fractal);
    else if (keysym == XK_Left 
            || keysym == XK_A 
            || keysym == XK_a)
        fractal->shift_x += (0.5 * fractal->zoom);
    else if (keysym == XK_Right
            || keysym == XK_D 
            || keysym == XK_d)
        fractal->shift_x -= (0.5 * fractal->zoom);
    else if (keysym == XK_Up
            || keysym == XK_W 
            || keysym == XK_w)
        fractal->shift_y -= (0.5 * fractal->zoom);
    else if (keysym == XK_Down
            || keysym == XK_S 
            || keysym == XK_s)
        fractal->shift_y += (0.5 * fractal->zoom);
    else if (keysym == XK_plus)
        fractal->definition += 10
    else if (keysym == XK_minus)
        fractal->definition -= 10
    fractal_render(fractal);
    return (0);
}

int    mouse_handler(int button, int x, int y, t_fractal *fractal)
{
    if (button == Button5)
        fractal->zoom *= 0.95;
    else if (button == Button4)
        fractal->zoom *= 1.05;
    fractal_render(fractal);
    return (0);
}

int julia_track(int x, int y, t_fractal *fractal)
{
    if (!ft_strncmp(fractal->name, "julia", 5))
    {
        fractal->julia_x = map(x, -2.5, 1.0, WIDTH) * fractal->zoom + fractal->shift_x;
        fractal->julia_y = map(y, 1.25, -1.25, HEIGHT) * fractal->zoom + fractal->shift_y;
        fractal_render(fractal);
    }
    return (0);
}