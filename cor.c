/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctete <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:26:20 by ctete             #+#    #+#             */
/*   Updated: 2024/08/29 10:26:45 by ctete            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"
#include <math.h>

int color1(int cor, double i)
{
    int r;
    int g;
    int b;

    // Ajuste dos coeficientes para cores mais vivas
    r = (int)(sin(3.14 * i) * 255);
    //g = (int)(sin(3.14 * (ti + 0.33)) * 255);
    b = (int)(sin(3.14 * (i + 0.66)) * 255);

    // Combina as componentes de cor em um valor de 24 bits
    cor = (r << 4) | (g << 8) | b;
    
    return cor;
}


int	color(int i, int limite_interacao, int color_fractol)
{
	double	t;
	int		color;

	color = 0;
	t = (double)i / (double)limite_interacao;
	if (color_fractol == 2)
		color = color1(color * 22, t);
	
	return (color);
}
