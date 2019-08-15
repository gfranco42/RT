/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refraction.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 12:14:47 by gfranco           #+#    #+#             */
/*   Updated: 2019/08/14 16:30:40 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void		indice_clear(t_base *base, t_prim *prim)
{
	if (base->in == TRUE)
	{
		base->tools.n1 = base->tools.n2;
		base->tools.n2 = prim[base->tools.i].refract;
	}
}

t_color		refraction(t_base base, t_prim *prim, t_i i, t_color refract_color)
{
	t_vector	inter_p;
	double		transparence;
	double		n;
	double		cost;
	double		sint;

//	double tmp = base->tools.n1;
	transparence = prim[base.tools.i].transparence;
	inter_p = vec_add(base.ray.origin, vec_mult_d(base.ray.dir, base.tools.t));
	base.ray.origin = vec_add_double(inter_p, 0.0);
	base.normal = getnmpri(prim, base.ray.origin, base, base.tools.t);
	cost = clamp(-1.0, 1.0, dot(base.ray.dir, base.normal));
	if (cost < 0)
	{
		// indice_clear(base, prim);
		cost *= -1;
	}
	else
	{
		ft_swap_double(&base.tools.n1, &base.tools.n2);
//		base->tools.n1 = base->tools.n2;
		//base->tools.n2 = 1.0;
		base.normal = vec_mult_d(base.normal, -1.0);
	}
	n = base.tools.n1 / base.tools.n2;
	sint = 1.0 - n * n * (1.0 - cost * cost);
	//	reflection;
	// if ((sint < 0 && base->in == FALSE) || (sint > 0 && base->in == FALSE))
	// else
	if (sint >= 0 && base.in == FALSE)
	{
		base.ray.dir.x = (base.ray.dir.x + cost * base.normal.x) * n - base.normal.x * sqrtf(sint);
		base.ray.dir.y = (base.ray.dir.y + cost * base.normal.y) * n - base.normal.y * sqrtf(sint);
		base.ray.dir.z = (base.ray.dir.z + cost * base.normal.z) * n - base.normal.z * sqrtf(sint);
		base.ray.dir = nrmz(base.ray.dir);
	}
	inter_refract(prim, i, &base, base.normal);
	if (base.tools.t < MAX_DIST)
	{
		// recup color obj
		// refract_color = get_color_prim(prim, base);
		// mult color par ambient
		// refract_color = color_mult_value(refract_color,
		// ambient_l(nrmz(base.ray.dir), base.normal, 0.5));
		// add diffuse && specular
		// refract_color = check_shadow(prim, i, base, refract_color);
		// keep % light
		// refract_color = color_mult_value(refract_color,
		// transparence / 100);
		refract_color = shade(base, prim, i, refract_color);
	}
	else
		refract_color = color_define_value(0, 0, 0);
	return (refract_color);
	// inter_refract(prim, i, base, base->normal);
//	printf("n1: %lf, n2: %lf\n", base->tools.n1, base->tools.n2);
/*	else
	{
		reflect_algo(base, prim, i);
	}*/

	// printf("n1: %lf, n2: %lf, n: %lf, cost: %lf, sint: %lf nm.x: %lf nm.y: %lf nm.z: %lf\n", base->tools.n1, base->tools.n2, n, cost, sint, base->normal->x, base->normal->y, base->normal->z);
	// printf("origin.x: %lf, origin.y: %lf, origin.z: %lf, dir.x: %lf, dir.y: %lf, dir.z: %lf   in:%d\n", base->ray.origin.x, base->ray.origin.y, base->ray.origin.z, base->ray.dir.x, base->ray.dir.y, base->ray.dir.z, base->in);
}

/*void		refract_algo(t_base *base, t_i *i, t_prim *prim)
{
	t_vector	base->normal;

	base->normal = vec_create(0.0, 0.0, 0.0);
	i->ref = -1;
	while (base->tools.t < 200000 && prim[base->tools.i].type != CAMERA
	&& prim[base->tools.i].type != LIGHT && prim[base->tools.i].refract > 0
	&& ++i->ref < 100)
	{
		refraction(base, prim, &base->normal);
		inter_refract(prim, i, base, base->normal);
//		printf("                                   %d\n", i->ref);
		if (i->ref == 2)
			exit(0);
	}
	base->tools.n1 = 1.0;
//	if (prim[base->tools.i].type == SPHERE)
//		exit(0);
}*/
