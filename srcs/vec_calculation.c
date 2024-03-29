/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_calculation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 11:37:02 by gfranco           #+#    #+#             */
/*   Updated: 2019/07/25 15:35:40 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_vector		vec_add(t_vector a, t_vector b)
{
	t_vector	vec;

	vec.x = a.x + b.x;
	vec.y = a.y + b.y;
	vec.z = a.z + b.z;
	return (vec);
}

t_vector		vec_sub(t_vector a, t_vector b)
{
	t_vector	vec;

	vec.x = a.x - b.x;
	vec.y = a.y - b.y;
	vec.z = a.z - b.z;
	return (vec);
}

t_vector		vec_mult(t_vector a, t_vector b)
{
	t_vector	vec;

	vec.x = a.x * b.x;
	vec.y = a.y * b.y;
	vec.z = a.z * b.z;
	return (vec);
}

t_vector		vec_div(t_vector a, t_vector b)
{
	t_vector	vec;

	vec.x = a.x / b.x;
	vec.y = a.y / b.y;
	vec.z = a.z / b.z;
	return (vec);
}

t_vector		vec_create(double a, double b, double c)
{
	t_vector	vector;

	vector.x = a;
	vector.y = b;
	vector.z = c;
	return (vector);
}
