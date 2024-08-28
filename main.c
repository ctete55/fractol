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
	
}

int 	main()
{
	t_dados data;
	point(&data);
	mlx_hook(data.win, 17, 0, close_win, &data);
	/*t_data  *a;
	a-> width = 500;
	a-> heigth = 600;
	a->mlx = mlx_init();
	a->win = mlx_new_window(a->mlx, a->width, a->heigth,"fracto");*/

	mlx_loop(data.mlx);
}
