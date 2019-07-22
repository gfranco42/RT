/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refraction.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 12:14:47 by gfranco           #+#    #+#             */
/*   Updated: 2019/07/22 18:47:59 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void		refraction(t_base *base, t_prim *prim)
{
	t_vector	normal;
	t_vector	inter_p;
	double		n;
	double		cost;
	double		sint;

	inter_p = vec_add(base->ray.origin, vec_mult_d(base->ray.dir, base->tools.t));
	base->ray.origin.x = inter_p.x;
	base->ray.origin.y = inter_p.y;
	base->ray.origin.z = inter_p.z;

	normal = getnmpri(prim, base->ray.origin, *base, base->tools.t);

	n = base->tools.n1 / base->tools.n2;
	cost = dot(base->ray.dir, normal);
	sint = n * n * (1 - cost * cost);

	base->ray.dir.x = n * base->ray.dir.x - (n * cost + sqrt(1 - sint * sint))
	* normal.x;
	base->ray.dir.y = n * base->ray.dir.y - (n * cost + sqrt(1 - sint * sint))
	* normal.y;
	base->ray.dir.z = n * base->ray.dir.z - (n * cost + sqrt(1 - sint * sint))
	* normal.z;
	base->ray.dir = nrmz(base->ray.dir);
//	printf("%lf, %lf, %lf", base->ray.dir.x, base->ray.dir.y, base->ray.dir.z);
	//premier indice de refract est egale a l'objet qu'on vient de traverser
	base->tools.n1 = prim[base->tools.i].refract;
}

void		refraction_algo(t_base *base, t_i *i, t_prim *prim)
{
	while (base->tools.t < 200000 && prim[base->tools.i].type != CAMERA
	&& prim[base->tools.i].type != LIGHT && prim[base->tools.i].refract > 0)
	{
		refraction(base, prim);
		intersect(prim, i, base);
	}
}
