/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 09:57:33 by jbarbate          #+#    #+#             */
/*   Updated: 2023/01/24 14:39:20 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_zoom(t_data *data)
{
	data->fractal->zoom *= 1.1;
	data->fractal->imax *= 1.1;
	data->fractal->x1 /= 1.1;
	data->fractal->x2 *= 1.1;
	data->fractal->y1 /= 1.1;
	data->fractal->y2 *= 1.1;
	ft_sumdata(data);
}

void	ft_unzoom(t_data *data)
{
	data->fractal->zoom /= 1.1;
	data->fractal->imax /= 1.1;
	data->fractal->x1 *= 1.1;
	data->fractal->x2 /= 1.1;
	data->fractal->y1 *= 1.1;
	data->fractal->y2 /= 1.1;
	ft_sumdata(data);
}

void	ft_mousezoom(t_data *data, int i, int j)
{
	long double x;
	long double y;

	data->fractal->zoom *= 1.1;
	if (data->fractal->imax > 1)
		data->fractal->imax *= 1.1;
	x = data->fractal->x1_max + (data->fractal->x2_max - data->fractal->x1_max)
		* i / 810;
	y = data->fractal->y1_max + (data->fractal->y2_max - data->fractal->y1_max)
		* j / 720;
//	data->x = x;
//	data->y = y;
	printf("x -> %Lf, y -> %Lf", x, y);
	data->fractal->x1 = x - 2;
	data->fractal->x2 = x + 2;
	data->fractal->y1 = y - 2;
	data->fractal->y2 = y + 2;
	ft_summousedata(data);
}

void	ft_mouseunzoom(t_data *data, int i, int j)
{
	long double x;
	long double y;

	data->fractal->zoom /= 1.1;
	if (data->fractal->imax > 10)
		data->fractal->imax /= 1.05;
	x = data->fractal->x1_max + (data->fractal->x2_max - data->fractal->x1_max)
		* i / 810;
	y = data->fractal->y1_max + (data->fractal->y2_max - data->fractal->y1_max)
		* j / 720;
	printf("x -> %Lf, y -> %Lf", x, y);
	data->fractal->x1 = x - 2;
	data->fractal->x2 = x + 2;
	data->fractal->y1 = y - 2;
	data->fractal->y2 = y + 2;
	ft_summousedata(data);
}
