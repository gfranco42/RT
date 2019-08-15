/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 16:15:18 by gfranco           #+#    #+#             */
/*   Updated: 2019/08/14 16:30:32 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

double		intersect_prim_first(t_prim *prim, int i, t_base base)
{

	if (prim[i].type == SPHERE)
		base.tools.t = sphere_intersect(prim[i].sphere, base.ray, base.tools.t);
	else if (prim[i].type == PLANE)
		base.tools.t = plane_intersect(prim[i].plane, base.ray, base.tools.t);
	else if (prim[i].type == CONE)
		base.tools.t = cone_intersect(prim[i].cone, base.ray, base.tools.t);
	else if (prim[i].type == CYLINDER)
		base.tools.t = cylinder_intersect(prim[i].cyl, base.ray, base.tools.t);
	return (base.tools.t);
}

//			renvoie la distance et l'index de l'objet qui a une intersection
//			premiere intersection a partir de la camera
void		intersect_first(t_prim *prim, t_i *i, t_base *base)
{
	i->dbl = MAX_DIST;
	base->tools.t = MAX_DIST;
	i->i = -1;
	//		i->i cherche l'objet
	//		base.tools.i == l'objet en cours d'avant
	while(++i->i < i->nb)
	{
		i->dbl = intersect_prim_first(prim, i->i, *base);
		if (i->dbl < base->tools.t)
		{
			base->tools.t = i->dbl;
			base->tools.i = i->i;
		}
	}
	// premierlancer de rayon depuis la cam:
	if (is_prim(prim, *base) == TRUE && prim[base->tools.i].refract > 0.0)
	{
	//	printf("AAAA\n");
		base->tools.n1 = 1.0;
		base->tools.n2 = prim[base->tools.i].refract;
		base->in = TRUE;
	}
}
