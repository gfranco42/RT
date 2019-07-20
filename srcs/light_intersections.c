/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_intersections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 11:10:41 by gfranco           #+#    #+#             */
/*   Updated: 2019/07/18 11:15:32 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

int			sphere_light_int(t_sphere sphere, t_light light, t_vector inter_p)
{
	t_vector	o_center;
	t_vector	lr;
	double		r[3];
	double		t[3];
	double		disc;

	o_center = vec_sub(inter_p, sphere.center);
	lr = vec_sub(light.src, inter_p);
	r[0] = dot(lr, lr);
	r[1] = 2 * dot(o_center, lr);
	r[2] = dot(o_center, o_center) - sphere.radius * sphere.radius;
	disc = r[1] * r[1] - 4.0 * r[0] * r[2];
	if (disc < 0)
		return (0);
	disc = sqrt(disc);
	t[2] = (-r[1] + disc) / (2 * r[0]);
	t[1] = (-r[1] - disc) / (2 * r[0]);
	t[0] = (t[1] < 0) ? t[2] : t[1];
	if (t[0] >= 0 && t[0] <= 1)
		return (1);
	return (0);
}

int			cyl_light_inter(t_cylinder cyl, t_light light, t_vector inter_p)
{
	t_vector	o_center;
	t_vector	lr;
	double		r[3];
	double		t[3];
	double		disc;

	o_center = vec_sub(inter_p, cyl.center);
	lr = vec_sub(light.src, inter_p);
	r[0] = dot(lr, lr) - dot(lr, cyl.dir) * dot(lr, cyl.dir);
	r[1] = 2 * (dot(lr, o_center) - dot(lr, cyl.dir)
	* dot(o_center, cyl.dir));
	r[2] = dot(o_center, o_center) - dot(o_center, cyl.dir)
	* dot(o_center, cyl.dir) - cyl.radius * cyl.radius;
	disc = r[1] * r[1] - 4.0 * r[0] * r[2];
	if (disc < 0)
		return (0);
	disc = sqrt(disc);
	t[2] = (-r[1] + disc) / (2 * r[0]);
	t[1] = (-r[1] - disc) / (2 * r[0]);
	t[0] = (t[1] < 0) ? t[2] : t[1];
	if (t[0] >= 0 && t[0] <= 1)
		return (1);
	return (0);
}

int			cone_light_inter(t_cone cone, t_light light, t_vector inter_p)
{
	t_vector	o_tip;
	t_vector	lr;
	double		r[3];
	double		t[3];
	double		disc;

	o_tip = vec_sub(inter_p, cone.tip);
	lr = vec_sub(light.src, inter_p);
	r[0] = dot(lr, lr) - (1 + cone.angle * cone.angle)
	* dot(lr, cone.dir) * dot(lr, cone.dir);
	r[1] = 2 * (dot(lr, o_tip) - (1 + cone.angle * cone.angle)
	* dot(lr, cone.dir) * dot(o_tip, cone.dir));
	r[2] = dot(o_tip, o_tip) - (1 + cone.angle * cone.angle)
	* dot(o_tip, cone.dir) * dot(o_tip, cone.dir);
	disc = r[1] * r[1] - 4.0 * r[0] * r[2];
	if (disc < 0)
		return (0);
	disc = sqrt(disc);
	t[2] = (-r[1] + disc) / (2 * r[0]);
	t[1] = (-r[1] - disc) / (2 * r[0]);
	t[0] = (t[1] < 0) ? t[2] : t[1];
	if (t[0] >= 0 && t[0] <= 1)
		return (1);
	return (0);
}

int		plane_light_inter(t_plane plane, t_light light)
{
	t_vector	o_center;
	int			t;

	o_center.x = plane.point.x - light.src.x;
	o_center.y = plane.point.y - light.src.y;
	o_center.z = plane.point.z - light.src.z;
	t = -dot(o_center, plane.normal) / dot(nrmz(light.ray),
	nrmz(plane.normal));
	if (t >= 0 && t <= 1)
		return (1);
	return (0);
}
