#include "./includes/fractol.h"
#include "./minilibx-linux/mlx.h"
#include <unistd.h>
#include <stdlib.h> 

#define LARGURA 960
#define ALTURA 580
static int	point(t_dados *a)
{
	
	a-> width = 960;
	a-> heigth = 800;
	a->mlx = mlx_init();
	if(a->mlx == NULL)
		printf("caraapau");
	
	a->win = mlx_new_window(a->mlx, a->width, a->heigth,"fractol");
	if(a->win == NULL)
	{
		free(a->win);
		return (1);
	}
	a->img = mlx_new_image(a->mlx, LARGURA * 2 , ALTURA * 2 );
	if(a->img == NULL)
	{
		free(a->img);
		return (1);
	}
	a->addr = mlx_get_data_addr(a->img, &a->pixel, &a->tam, &a->endian);
	a->zoom = 1.1;
	a->eixo_x = 1.0;
	a->eixo_y = 1.0;
	a->color_fracts = 2;
	return (0);
}
int	handle_args(int argc, char **argv, t_dados *data)
{
	if(argc == 2 && ft_strcmp(argv[1], "mandelbrot") == 0)
	{
		draw_mandelbrot(data);
	}	

	else if(argc == 4 && (ft_strcmp(argv[1], "julia") == 0))
	{
		/*data->x = ft_atodbl(av[2]);
		data->y = ft_atodbl(av[3]);
		draw_julia(dados);
		mlx_hook(dados->win_ptr, 2, 1L, eventos2, dados);
		mlx_mouse_hook(dados->win_ptr, mouse_eventos2, dados);
		*/
	
	}
	return 0;
}

int	main(int argc, char **argv)
{
	t_dados data;
	argv_erro(argc, argv, &data);
	point(&data);
	handle_args(argc, argv, &data);
	mlx_hook(data.win, 17, 0, close_win, &data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 1, 1);
	mlx_loop(data.mlx);
	return 0;
}


