/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 14:40:24 by gfranco           #+#    #+#             */
/*   Updated: 2019/07/25 15:43:14 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void		reflection(t_base *base, t_prim *prim)
{
	t_vector	normal;
	t_vector	inter_p;

	inter_p = vec_add(base->ray.origin, vec_mult_d(base->ray.dir, base->tools.t));
	base->ray.origin.x = inter_p.x;
	base->ray.origin.y = inter_p.y;
	base->ray.origin.z = inter_p.z;
	normal = getnmpri(prim, base->ray.origin, *base, base->tools.t);
	base->ray.dir.x = base->ray.dir.x - 2 * dot(normal, base->ray.dir)
	* normal.x;
	base->ray.dir.y = base->ray.dir.y - 2 * dot(normal, base->ray.dir)
	* normal.y;
	base->ray.dir.z = base->ray.dir.z - 2 * dot(normal, base->ray.dir)
	* normal.z;
	base->ray.dir = nrmz(base->ray.dir);
}

void		reflect_algo(t_base *base, t_prim *prim, t_i *i)
{
	i->ref = -1;
	while (base->tools.t < 200000 && prim[base->tools.i].type != CAMERA
	&& prim[base->tools.i].type != LIGHT && prim[base->tools.i].reflect == TRUE
	&& ++i->ref < MAXDEPTH)
	{
		reflection(base, prim);
		intersect(prim, i, base, vec_create(0.0, 0.0, 0.0));
	}
}
