/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_mandel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctete <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:06:31 by ctete             #+#    #+#             */
/*   Updated: 2024/08/29 12:10:59 by ctete            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"
#include "./minilibx-linux/mlx.h"

void	argv_erro(int argc, char **argv , t_dados *a)
{
	if((argc == 2 && ft_strcmp(argv[1], "mandelbrot") != 0) || argc == 1)
	{	
		
		printf("comando invalido\n");
		printf("comando certo <mandelbrot>\n");
		exit(0);
		free(a->win);
	}
}



