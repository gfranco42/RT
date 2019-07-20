/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 14:40:24 by gfranco           #+#    #+#             */
/*   Updated: 2019/07/20 19:11:33 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_vector	get_nm_prim(t_prim *prim, t_vector inter_p, t_base base, double t)
{
	t_vector	nm;

	if (prim[base.tools.i].type == SPHERE)
	{
		(void)base;
		(void)t;
		nm = getnormal_sphere(prim[base.tools.i].sphere, inter_p);
	}
	else if (prim[base.tools.i].type == CONE)
		nm = getnm_co(inter_p, prim[base.tools.i].cone, base.ray, t);
	else if (prim[base.tools.i].type == CYLINDER)
		nm = gtnm_cyl(prim[base.tools.i].cyl, inter_p, base.ray, t);
	else
		nm = vec_add_double(prim[base.tools.i].plane.normal, 0);
	return (nm);
}

void		reflection(double t, t_base *base, t_prim *prim)
{
	t_vector	normal;
	t_vector	inter_p;

	(void)t;
	inter_p = vec_add(base->ray.origin, vec_mult_d(base->ray.dir, base->tools.t));
	//printf("ORIGIN   x: %lf, y: %lf, z: %lf\n", inter_p.x, inter_p.y, inter_p.z);
	base->ray.origin.x = inter_p.x;
	base->ray.origin.y = inter_p.y;
	base->ray.origin.z = inter_p.z;
	normal = get_nm_prim(prim, base->ray.origin, *base, t);
/*	normal.x = prim[base->tools.i].plane.normal.x;
	normal.y = prim[base->tools.i].plane.normal.y;
	normal.z = prim[base->tools.i].plane.normal.z;*/
	base->ray.dir.x = base->ray.dir.x - 2 * dot(normal, base->ray.dir)
	* normal.x;
	base->ray.dir.y = base->ray.dir.y - 2 * dot(normal, base->ray.dir)
	* normal.y;
	base->ray.dir.z = base->ray.dir.z - 2 * dot(normal, base->ray.dir)
	* normal.z;
	base->ray.dir = nrmz(base->ray.dir);
//	printf("2    t: %lf\n", base->tools.t);
//	printf("2    i: %d\n", base->tools.i);
//	printf("2    origin: %lf %lf %lf\n", base->ray.origin.x, base->ray.origin.y, base->ray.origin.z);
//	printf("2    direction: %lf %lf %lf\n", base->ray.dir.x, base->ray.dir.y, base->ray.dir.z);
}
