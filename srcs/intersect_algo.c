/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 16:15:18 by gfranco           #+#    #+#             */
/*   Updated: 2019/07/20 18:00:20 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	get_tools_value(t_base *base, t_i i)
{
	base->tools.t = i.tmp;
	base->tools.i = i.i;
}

double		intersect_prim_first(t_prim *prim, int i, t_base base)
{

	//printf("i: %d, base i: %d\n", i, base.tools.i);
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
void		intersect_first(t_prim *prim, t_i *i, t_base *base)
{
	i->dbl = 200000;
	base->tools.t = 200000;
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
}

double		intersect_prim(t_prim *prim, t_i i, t_base base)
{

	if (prim[i.i].type == SPHERE && base.tools.i != i.i)
	{
		base.tools.t = sphere_intersect(prim[i.i].sphere, base.ray, base.tools.t);
	}
	else if (prim[i.i].type == PLANE && base.tools.i != i.i)
		base.tools.t = plane_intersect(prim[i.i].plane, base.ray, base.tools.t);
	else if (prim[i.i].type == CONE && base.tools.i != i.i)
		base.tools.t = cone_intersect(prim[i.i].cone, base.ray, base.tools.t);
	else if (prim[i.i].type == CYLINDER && base.tools.i != i.i)
		base.tools.t = cylinder_intersect(prim[i.i].cyl, base.ray, base.tools.t);
	return (base.tools.t);
}

//			renvoie la distance et l'index de l'objet qui a une intersection
void		intersect(t_prim *prim, t_i *i, t_base *base)
{
	base->tools.t = 200000;
	i->i = -1;
	while (++i->i < i->nb)
	{
		i->dbl = intersect_prim(prim, *i, *base);
//		printf("dbl: %lf t:%lf\n", i->dbl, base->tools.t);
		if (i->dbl < base->tools.t)
		{
			base->tools.t = i->dbl;
			base->tools.i = i->i;
		}
	}
//	printf("   3    t: %lf\n", base->tools.t);
//	printf("   3    i: %d\n", base->tools.i);
//	printf("   3    origin: %lf %lf %lf\n", base->ray.origin.x, base->ray.origin.y, base->ray.origin.z);
//	printf("   3    direction: %lf %lf %lf\n", base->ray.dir.x, base->ray.dir.y, base->ray.dir.z);
}
