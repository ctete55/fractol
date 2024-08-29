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

#define LARGURA 950
#define ALTURA 800

#include "./includes/fractol.h"
#include "./minilibx-linux/mlx.h"
#include <math.h>
#include <stdlib.h>


static void	coordenadas_t(t_coordenar *c, int x, int y, t_dados *d)
{
	c->c_re = (x - 400.0 + d->eixo_x) * 4.0 / (LARGURA * d->zoom);
	c->c_im = (y - 300.0 + d->eixo_y) * 4.0 / (ALTURA * d->zoom);
	c->z_re = c->c_re;
	c->z_im = c->c_im;
}

static int	mandelbrot_interacao(t_coordenar *c, int limite_inteiro)
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

static void	pixel_color(t_dados *d, int x, int y, int cor)
{
	*(int *)(d->addr + (y * d->tam + x * (d->pixel / 8))) = cor;
}

void	draw_mandelbrot(t_dados *d)
{
	t_coordenar	c;
	int			i;
	int			y;
	int			x;
	int			limite_inteiro;

	limite_inteiro = 100;
	y = 0;
	while (y < ALTURA)
	{
		x = 0;
		while (x < LARGURA)
		{
			coordenadas_t(&c, x, y, d);
			i = mandelbrot_interacao(&c, limite_inteiro);
			c.cor = cor(i, limite_inteiro, d->cor_fracts);
			pixel_color(d, x, y, c.cor);
			x++;
		}
		y++;
	}
}
