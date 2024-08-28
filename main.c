#include "./includes/fractol.h"
#include "./minilibx-linux/mlx.h"
#include <unistd.h>
#include <stdlib.h> 

static int	point(t_dados *a)
{
	
	a-> width = 960;
	a-> heigth = 800;
	a->mlx = mlx_init();
	if(a->mlx == NULL)
	{
		free(a->mlx);
		return (1);
	}
	a->win = mlx_new_window(a->mlx, a->width, a->heigth,"fracto");
	if(a->win == NULL)
	{
		free(a->win);
		return (1);
	}
	d->img = mlx_new_image(d->mlx_ptr, LARGURA * 2, ALTURA * 2);
	if(d->img == NULL)
	{
		free(d->img);
		return (1);
	}
	d->addr = mlx_get_data_addr(d->img_ptr, &d->pixel, &d->tam, &d->endian);
	d->zoom = 1.1;
	d->eixo_x = 1.0;
	d->eixo_y = 1.0;
	d->cor_fracts = 2;
	return (0);
}

int	main()
{
	t_dados data;
	point(&data);
	mlx_hook(data.win, 17, 0, close_win, &data);
	mlx_loop(data.mlx);
}
