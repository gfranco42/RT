/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 11:10:40 by gfranco           #+#    #+#             */
/*   Updated: 2019/07/20 17:05:28 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

int			sphere_intersect(t_sphere sphere, t_ray ray, double t)
{
	t_vector	o_center;
	double		r[3];
	double		d[2];
	double		disc;

	o_center = vec_sub(ray.origin, sphere.center);
	r[0] = dot(ray.dir, ray.dir);
	r[1] = 2 * dot(ray.dir, o_center);
	r[2] = dot(o_center, o_center) - sphere.radius * sphere.radius;
	disc = r[1] * r[1] - 4.0 * r[0] * r[2];
	if (disc < 0)
		return (t);
	else
	{
		disc = sqrt(disc);
		d[1] = (-r[1] + disc) / (2 * r[0]);
		d[0] = (-r[1] - disc) / (2 * r[0]);
		t = (d[0] < 0) ? d[1] : d[0];
		if (t > 0)
			return (t);
	}
	return (200000);
}

int			cylinder_intersect(t_cylinder cyl, t_ray ray, double t)
{
	t_vector	o_center;
	double		r[3];
	double		d[2];
	double		disc;

	o_center = vec_sub(ray.origin, cyl.center);
	r[0] = dot(ray.dir, ray.dir) - dot(ray.dir, cyl.dir)
	* dot(ray.dir, cyl.dir);
	r[1] = 2 * (dot(ray.dir, o_center) - dot(ray.dir, cyl.dir)
	* dot(o_center, cyl.dir));
	r[2] = dot(o_center, o_center) - dot(o_center, cyl.dir)
	* dot(o_center, cyl.dir) - cyl.radius * cyl.radius;
	disc = r[1] * r[1] - 4.0 * r[0] * r[2];
	if (disc < 0)
		return (t);
	else
	{
		disc = sqrt(disc);
		d[1] = (-r[1] + disc) / (2 * r[0]);
		d[0] = (-r[1] - disc) / (2 * r[0]);
		t = (d[0] < 0) ? d[1] : d[0];
		if (t > 0)
			return (t);
	}
	return (200000);
}

int			cone_intersect(t_cone cone, t_ray ray, double t)
{
	t_vector	o_tip;
	double		r[3];
	double		d[2];
	double		disc;

	o_tip = vec_sub(ray.origin, cone.tip);
	r[0] = dot(ray.dir, ray.dir) - (1 + cone.angle * cone.angle)
	* dot(ray.dir, cone.dir) * dot(ray.dir, cone.dir);
	r[1] = 2 * (dot(ray.dir, o_tip) - (1 + cone.angle * cone.angle)
	* dot(ray.dir, cone.dir) * dot(o_tip, cone.dir));
	r[2] = dot(o_tip, o_tip) - (1 + cone.angle * cone.angle)
	* dot(o_tip, cone.dir) * dot(o_tip, cone.dir);
	disc = r[1] * r[1] - 4.0 * r[0] * r[2];
	if (disc < 0)
		return (t);
	else
	{
		disc = sqrt(disc);
		d[1] = (-r[1] + disc) / (2 * r[0]);
		d[0] = (-r[1] - disc) / (2 * r[0]);
		t = (d[0] < 0) ? d[1] : d[0];
		if (t > 0)
			return (t);
	}
	return (200000);
}

int		plane_intersect(t_plane plane, t_ray ray, double t)
{
	t_vector	o_center;
	double		xv;
	double		dv;

	o_center = vec_sub(ray.origin, plane.point);
	o_center = vec_mult_d(o_center, -1);
	xv = dot(o_center, plane.normal);
	if ((dv = dot(ray.dir, plane.normal)) <= 0)
		return (t);
	t = xv / dv;
	if (t > 0)
		return (t);
	return (200000);
}
