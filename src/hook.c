/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:16:08 by jbarbate          #+#    #+#             */
/*   Updated: 2023/01/25 09:08:24 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_mlxkey(int keycode, t_data *data)
{
	printf("%i\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == 126)
		ft_upkey(data);
	else if (keycode == 125)
		ft_downkey(data);
	else if (keycode == 123)
		ft_leftkey(data);
	else if (keycode == 124)
		ft_rightkey(data);
	return (0);
}

int	ft_mlxmouse(int keycode, int x, int y, t_data *data)
{
	(void)data;
	if (keycode == 5)
	{
		printf("%i\n", keycode);
		printf("x ->%i\n", x);
		printf("y ->%i\n", y);
		ft_mousezoom(data);
	}
	if (keycode == 4)
	{
		printf("%i\n", keycode);
		printf("x ->%i\n", x);
		printf("y ->%i\n", y);
		ft_mouseunzoom(data);
	}
	else
		printf("%i\n", keycode);
	return (0);
}
