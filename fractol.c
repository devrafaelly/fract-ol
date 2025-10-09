#include "fractol.h"

void    cleanup(t_data *data)
{
    // destruir imagem, SE EXISTIR
    if (data->img)
        mlx_destroy_image(data->mlx, data->img);
    // destruir janela, SE EXISTIR
    if (data->win)
        mlx_destroy_window(data->mlx, data->win);
    // destruir display
    mlx_destroy_display(data->mlx);
    // liberar struct
    free (data->mlx);
    data->mlx = NULL;
}

int init_program(t_data *data)
{
    data->mlx = mlx_init();
    if (!data->mlx)
        return (1);
    data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Fractol - rafaoliv");
    if(!data->win)
    {
        cleanup(data);
        return (1);
    }
    return (0);
}

int main(void)
{
    t_data  data;

    init_program(&data);
    mlx_loop(data.mlx);
    return (0);
}
