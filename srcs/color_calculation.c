/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_calculation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 12:26:25 by gfranco           #+#    #+#             */
/*   Updated: 2019/07/22 14:41:59 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_color		color_add_value(t_color color, double r, double g, double b)
{
	color.r = color.r + r;
	color.g = color.g + g;
	color.b = color.b + b;
	return (color);
}

void		print_pixel(t_mlx mlx, t_tools tools, t_color color)
{
	mlx.str[(tools.y * WIDTH + tools.x) * 4] = color.b;
	mlx.str[(tools.y * WIDTH + tools.x) * 4 + 1] = color.g;
	mlx.str[(tools.y * WIDTH + tools.x) * 4 + 2] = color.r;
}

t_color		color_define_value(int r, int g, int b)
{
	t_color		color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

t_color		color_add(t_color c1, t_color c2)
{
	t_color		color;

	color.r = c1.r + c2.r;
	color.g = c1.g + c2.g;
	color.b = c1.b + c2.b;
	return (color);
}
