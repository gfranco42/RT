/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refraction.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 12:14:47 by gfranco           #+#    #+#             */
/*   Updated: 2019/07/26 12:38:16 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void		refraction(t_base *base, t_prim *prim, t_vector *normal)
{
	t_vector	inter_p;
	double		n;
	double		cost;
	double		sint;

//	double tmp = base->tools.n1;
	inter_p = vec_add(base->ray.origin, vec_mult_d(base->ray.dir, base->tools.t));
	base->ray.origin = vec_add_double(inter_p, 0.0);
	*normal = getnmpri(prim, base->ray.origin, *base, base->tools.t);
	cost = clamp(-1.0, 1.0, dot(base->ray.dir, *normal));
	if (cost < 0)
		cost *= -1;
	else
	{
		ft_swap_double(&base->tools.n1, &base->tools.n2);
//		base->tools.n1 = base->tools.n2;
		//base->tools.n2 = 1.0;
		*normal = vec_mult_d(*normal, -1.0);
	}
	n = base->tools.n1 / base->tools.n2;
	sint = 1.0 - n * n * (1.0 - cost * cost);
	if (sint >= 0)
	{
		base->ray.dir.x = (base->ray.dir.x + cost * normal->x) * n - normal->x * sqrtf(sint);
		base->ray.dir.y = (base->ray.dir.y + cost * normal->y) * n - normal->y * sqrtf(sint);
		base->ray.dir.z = (base->ray.dir.z + cost * normal->z) * n - normal->z * sqrtf(sint);
		base->ray.dir = nrmz(base->ray.dir);
	}
	printf("n1: %lf, n2: %lf\n", base->tools.n1, base->tools.n2);
/*	else
	{
		reflect_algo(base, prim, i);
	}*/

//	printf("n1: %lf, n2: %lf, n: %lf, cost: %lf, sint: %lf nm.x: %lf nm.y: %lf nm.z: %lf\n", base->tools.n1, base->tools.n2, n, cost, sint, normal->x, normal->y, normal->z);
//	printf("origin.x: %lf, origin.y: %lf, origin.z: %lf, dir.x: %lf, dir.y: %lf, dir.z: %lf   in:%d\n", base->ray.origin.x, base->ray.origin.y, base->ray.origin.z, base->ray.dir.x, base->ray.dir.y, base->ray.dir.z, base->in);
}

void		refraction_algo(t_base *base, t_i *i, t_prim *prim)
{
	t_vector	normal;

	normal= vec_create(0.0, 0.0, 0.0);
	i->ref = -1;
	while (base->tools.t < 200000 && prim[base->tools.i].type != CAMERA
	&& prim[base->tools.i].type != LIGHT && prim[base->tools.i].refract > 0
	&& ++i->ref < 10)
	{
		refraction(base, prim, &normal);
		intersect(prim, i, base, normal);
//		printf("                                   %d\n", i->ref);
	/*	if (i->ref == 2)
			exit(0);*/
	}
//	if (prim[base->tools.i].type == SPHERE)
//		exit(0);
}
