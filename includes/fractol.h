#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_dados
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		pixel;
	int		tam;
	int		endian;
	double	zoom;
	double	eixo_x;
	double	eixo_y;
	double	width;
	double	heigth;
	int		cor_fracts;
}	t_dados;





int	close_win(t_dados *parm);
#endif
