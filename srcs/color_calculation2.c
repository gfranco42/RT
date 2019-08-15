/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_calculation2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 16:59:54 by gfranco           #+#    #+#             */
/*   Updated: 2019/08/08 15:05:47 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_color		color_mult(t_color color1, t_color color2)
{
	color1.r *= color2.r;
	color1.g *= color2.g;
	color1.b *= color2.b;
	return (color1);
}

t_color		color_add(t_color c1, t_color c2)
{
	t_color		color;

	color.r = c1.r + c2.r;
	color.g = c1.g + c2.g;
	color.b = c1.b + c2.b;
	return (color);
}


t_color		color_sub(t_color color, t_color tmp)
{
	color.r -= tmp.r;
	color.g -= tmp.g;
	color.b -= tmp.b;
	return (color);
}
