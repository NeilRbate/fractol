/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:32:28 by jbarbate          #+#    #+#             */
/*   Updated: 2023/01/13 12:47:37 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 700
# define HEIGHT 700

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <math.h>
# include <stdio.h>

typedef struct	s_fractal
{
	double	x1;
	double	x2;
	double	y1;
	double	y2;
	double	zoom_x;
	double	zoom_y;
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	int		i;
	int		zoom;
	int		imax;
}				t_fractal;

typedef struct	s_data
{
	void		*img;
	char		*addr;
	void		*mlx;
	void		*win;
	t_fractal	*fractal;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			x;
	int			y;
}				t_data;

void	pixel_put(t_data *data, int x, int y, int color);
void	print_mandelbrot(t_data *data, t_fractal *fractal);
void	init_mandelbrot(t_data *data, t_fractal *fractal);
int		init(t_data *data);




#endif
