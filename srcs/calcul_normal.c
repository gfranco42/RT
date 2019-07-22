/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_normal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 11:10:37 by gfranco           #+#    #+#             */
/*   Updated: 2019/07/22 16:14:57 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_vector	getnormal_sphere(t_sphere sphere, t_vector inter_p)
{
	t_vector	normal;

	normal.x = sphere.center.x - inter_p.x;
	normal.y = sphere.center.y - inter_p.y;
	normal.z = sphere.center.z - inter_p.z;
	normal = nrmz(normal);
	return (normal);
}

t_vector	gtnm_cyl(t_cylinder cyl, t_vector inter_p, t_ray ray, double t)
{
	t_vector	normal;
	t_vector	o_center;
	double		m;

	o_center.x = ray.origin.x - cyl.center.x;
	o_center.y = ray.origin.y - cyl.center.y;
	o_center.z = ray.origin.z - cyl.center.z;
	m = dot(ray.dir, cyl.dir) * t + dot(o_center, cyl.dir);
	normal.x = inter_p.x - cyl.center.x - cyl.dir.x * m;
	normal.y = inter_p.y - cyl.center.y - cyl.dir.y * m;
	normal.z = inter_p.z - cyl.center.z - cyl.dir.z * m;
	return (nrmz(normal));
}

t_vector	getnm_co(t_vector inter_p, t_cone cone, t_ray ray, double t)
{
	t_vector	normal;
	t_vector	vec_minus;
	t_vector	o_center;
	double		m;

	o_center = vec_sub(ray.origin, cone.tip);
	m = dot(ray.dir, cone.dir) * t + dot(o_center, cone.dir);
	normal.x = cone.dir.x * m * (1 + cone.angle * cone.angle);
	normal.y = cone.dir.y * m * (1 + cone.angle * cone.angle);
	normal.z = cone.dir.z * m * (1 + cone.angle * cone.angle);
	vec_minus.x = inter_p.x - cone.tip.x - normal.x;
	vec_minus.y = inter_p.y - cone.tip.y - normal.y;
	vec_minus.z = inter_p.z - cone.tip.z - normal.z;
	normal = nrmz(vec_minus);
	if (dot(ray.dir, normal) > 0.0001)
		normal = vec_mult_d(normal, -1);
	return (normal);
}

t_vector	getnmpri(t_prim *prim, t_vector inter_p, t_base base, double t)
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
