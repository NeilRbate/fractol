/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:21:11 by jbarbate          #+#    #+#             */
/*   Updated: 2023/01/25 14:29:43 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

long double	ft_sum(char *nb)
{
	size_t		size;
	size_t		i;
	long double	temp;
	long double	value;

	i = 0;
	value = (long double)ft_atoi(nb);
	nb = ft_strchr(nb, '.');
	nb += 1;
	size = ft_strlen(nb);
	temp = (long double)ft_atoi(nb);
	while (i++ < size)
		temp /= 10;
	return (value + temp);
}

void	ft_print_error(void)
{
	ft_putendl_fd("error: invalid args.", 2);
	ft_putendl_fd("Use this format :", 2);
	ft_putendl_fd("For mandelbrot -> ./fractol mandelbrot", 2);
	ft_putstr_fd("For julia -> ./fractol julia ", 2);
	ft_putendl_fd("[optionnal value] [optionnal value]", 2);
}

int	dbctl(long double *value, char *nb)
{
	int		size;
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (nb[0] == '-')
		nb += 1;
	while (ft_isdigit(nb[i]) == 1 || nb[i] == '.')
	{
		if (nb[i] == '.')
			count++;
		i++;
	}
	size = ft_strlen(nb);
	if (size == i && count == 1)
		return (*value = ft_sum(nb), 1);
	else if (size == i && count == 0)
	{
		*value = (long double)ft_atoi(nb);
		return (1);
	}
	return (-1);
}

int	ft_twoarg(t_data *data, char **argv)
{
	if (ft_strlen("mandelbrot") == ft_strlen(argv[1])
		&& ft_strcmp("mandelbrot", argv[1]) == 0)
		return (0);
	if (ft_strlen("julia") == ft_strlen(argv[1])
		&& ft_strcmp("julia", argv[1]) == 0)
	{
		data->fractal->c_r = 0.29;
		data->fractal->c_i = 0.015;
		return (1);
	}
	return (ft_print_error(), -1);
}

int	ft_argctl(t_data *data, int argc, char **argv)
{
	size_t	size;

	if (argc < 2)
		return (ft_print_error(), -1);
	size = ft_strlen(argv[1]);
	if (argc == 2)
		return (ft_twoarg(data, argv));
	if (argc == 4)
	{
		if (ft_strlen(argv[2]) > 11 || ft_strlen(argv[3]) > 11)
			return (ft_putendl_fd("error: value is too big", 2), -1);
		if (ft_strlen("julia") == size && ft_strcmp("julia", argv[1]) == 0)
		{
			if (dbctl(&data->fractal->c_r, argv[2]) == 1
				&& dbctl(&data->fractal->c_i, argv[3]) == 1)
				return (1);
			return (ft_print_error(), -1);
		}
	}
	return (ft_print_error(), -1);
}
