/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_calculation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 12:26:25 by gfranco           #+#    #+#             */
/*   Updated: 2019/08/07 17:58:41 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void		print_pixel(t_mlx mlx, t_tools tools, t_color color)
{
	mlx.str[(tools.y * WIDTH + tools.x) * 4] = color.b;
	mlx.str[(tools.y * WIDTH + tools.x) * 4 + 1] = color.g;
	mlx.str[(tools.y * WIDTH + tools.x) * 4 + 2] = color.r;
}

t_color		color_mult_value(t_color color, double div)
{
	color.r = color.r * div;
	color.g = color.g * div;
	color.b = color.b * div;
	return (color);
}

t_color		color_add_value(t_color color, double r, double g, double b)
{
	color.r = color.r + r;
	color.g = color.g + g;
	color.b = color.b + b;
	return (color);
}

t_color		color_define_value(int r, int g, int b)
{
	t_color		color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

t_color		color_div_value(t_color color, int value)
{
	if (value != 0)
	{
		color.r /= value;
		color.g /= value;
		color.b /= value;
	}
	return (color);
}
