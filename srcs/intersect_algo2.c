/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_algo2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 12:01:24 by gfranco           #+#    #+#             */
/*   Updated: 2019/08/14 16:30:26 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

double		intersect_prim(t_prim *prim, t_i i, t_base base)
{

	if (prim[i.i].type == SPHERE)
		base.tools.t = sphere_intersect(prim[i.i].sphere, base.ray, base.tools.t);
	else if (prim[i.i].type == PLANE)
		base.tools.t = plane_intersect(prim[i.i].plane, base.ray, base.tools.t);
	else if (prim[i.i].type == CONE)
		base.tools.t = cone_intersect(prim[i.i].cone, base.ray, base.tools.t);
	else if (prim[i.i].type == CYLINDER)
		base.tools.t = cylinder_intersect(prim[i.i].cyl, base.ray, base.tools.t);
	return (base.tools.t);
}

void		inter_reflect(t_prim *prim, t_i i, t_base *base)
{
	int		tmp;

	tmp = base->tools.i;
	base->tools.t = MAX_DIST;
	i.i = -1;
	while (++i.i < i.nb)
	{
		i.dbl = intersect_prim_first(prim, i.i, *base);
		if (i.dbl < base->tools.t)
		{
			base->tools.t = i.dbl;
			base->tools.i = i.i;
		}
	}
}

void		inter_refract(t_prim *prim, t_i i, t_base *base, t_vector nm)
{
	int		tmp;

	tmp = base->tools.i;
	base->tools.t = MAX_DIST;
	i.i = -1;
	while (++i.i < i.nb)
	{
		while ((i.dbl = intersect_prim_first(prim, i.i, *base)) <= 0.0)
			move_origin(base, nm);
		if (i.dbl < base->tools.t)
		{
			base->tools.t = i.dbl;
			base->tools.i = i.i;
		}
	}
	if (base->tools.i == tmp)
		base->in = FALSE;
	else if  (base->tools.i != tmp && prim[base->tools.i].refract > 0.0)
		base->in = TRUE;
}
