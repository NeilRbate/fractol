/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 09:57:33 by jbarbate          #+#    #+#             */
/*   Updated: 2023/01/24 11:28:51 by jbarbate         ###   ########.fr       */
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
	data->fractal->zoom *= 1.1;
	data->fractal->imax *= 1.1;
	data->fractal->x1 /= 1.1;
	data->fractal->x2 *= 1.1;
	data->fractal->y1 /= 1.1;
	data->fractal->y2 *= 1.1;
	ft_summousedata(data, i, j);
}

void	ft_mouseunzoom(t_data *data, int i, int j)
{
	data->fractal->zoom /= 1.1;
	data->fractal->imax /= 1.1;
	data->fractal->x1 *= 1.1;
	data->fractal->x2 /= 1.1;
	data->fractal->y1 *= 1.1;
	data->fractal->y2 /= 1.1;
	ft_summousedata(data, i, j);
}
