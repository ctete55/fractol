/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctete <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 08:56:24 by ctete             #+#    #+#             */
/*   Updated: 2024/08/29 08:56:37 by ctete            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define w 950
#define h 800

#include "./includes/fractol.h"
#include "./minilibx-linux/mlx.h"
#include <math.h>
#include <stdlib.h>

static void	coord_t(t_coord *c, int x, int y, t_dados *d)
{
	c->c_re = (x - 600.0 + d->eixo_x) * 6.0 / (w * d->zoom);
	c->c_im = (y - 350.0 + d->eixo_y) * 8.0 / (h * d->zoom);
	c->z_re = c->c_re;
	c->z_im = c->c_im;
}

static int	mandelbrot_interacao(t_coord *c, int limite_inteiro)
{
	int	i;

	i = 0;
	while (i < limite_inteiro)
	{
		c->z_re2 = c->z_re * c->z_re;
		c->z_im2 = c->z_im * c->z_im;
		if (c->z_re2 + c->z_im2 > 4.0)
			break ;
		c->z_im = 2.0 * c->z_re * c->z_im + c->c_im;
		c->z_re = c->z_re2 - c->z_im2 + c->c_re;
		i++;
	}
	return (i);
}

static void	pixel_color(t_dados *d, int x, int y, int color)
{
	*(int *)(d->addr + (y * d->tam + x * (d->pixel / 8))) = color;
}

void	draw_mandelbrot(t_dados *d)
{
	t_coord		c;
	int			i;
	int			y;
	int			x;
	int			limite_inteiro;

	limite_inteiro = 100;
	y = 0;
	while (y < h)
	{
		x = 0;
		while (x < w)
		{
			coord_t(&c, x, y, d);
			i = mandelbrot_interacao(&c, limite_inteiro);
			c.cor = color(i, limite_inteiro, d->color_fracts);
			pixel_color(d, x, y, c.cor);
			x++;
		}
		y++;
	}
}
