/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_calculation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 11:28:17 by gfranco           #+#    #+#             */
/*   Updated: 2019/08/13 16:13:27 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

double		ambient_l(t_vector eye, t_vector normal, double intensity)
{
	return(dot(eye, normal) * intensity);
}

t_color		diffuse_l(t_vector normal, t_vector lr, t_color color, double i)
{
	t_color		diff;
	double		di;

	di = dot(normal, lr) * i;
	di = di < 0 ? 0 : di;
	di *= di;
	diff.r = color.r * di;
	diff.g = color.g * di;
	diff.b = color.b * di;
	return (diff);
}

t_color		specular_l(t_vector normal, t_vector half, t_color color, int sign)
{
	t_color		spec;
	double		p;
	double		dot_p;
	double		si;

	p = 100;
	dot_p = dot(normal, half) * sign;
	dot_p = dot_p < 0 ? 0 : dot_p;
	si = 3 * power(dot_p, p);
	spec.r = color.r * si;
	spec.g = color.g * si;
	spec.b = color.b * si;
	return (spec);
}

t_color		l_scale(t_color effect)
{
	effect.r = (effect.r / 255.0) / ((effect.r / 255.0) + 1) * 255.0;
	effect.g = (effect.g / 255.0) / ((effect.g / 255.0) + 1) * 255.0;
	effect.b = (effect.b / 255.0) / ((effect.b / 255.0) + 1) * 255.0;
	return (effect);
}

t_color		l_effect(t_color diff, t_color spec, double amb, t_color color)
{
	t_color		effect;

	effect.r = diff.r + spec.r + amb * color.r;
	effect.g = diff.g + spec.g + amb * color.g;
	effect.b = diff.b + spec.b + amb * color.b;
	effect.r = (effect.r / 255.0) / ((effect.r / 255.0) + 1) * 255.0;
	effect.g = (effect.g / 255.0) / ((effect.g / 255.0) + 1) * 255.0;
	effect.b = (effect.b / 255.0) / ((effect.b / 255.0) + 1) * 255.0;
	return (effect);
}
