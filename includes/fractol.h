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

typedef struct s_coordenar
{
	double	c_re;
	double	c_im;
	double	z_re;
	double	z_im;
	double	z_re2;
	double	z_im2;
	int		cor;
}	t_coordenar;




int	close_win(t_dados *parm);
void	draw_mandelbrot(t_dados *d);
int	ft_strcmp(char *s1, char *s2);
int	cor(int i, int limite_interacao, int cor_fractais);
void	argv_erro(int argc, char **argv , t_dados *a);
#endif
