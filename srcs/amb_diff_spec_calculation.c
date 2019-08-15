/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   amb_diff_spec_calculation.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 11:27:36 by gfranco           #+#    #+#             */
/*   Updated: 2019/08/14 17:07:26 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_color		cap(t_color color)
{
	color.r = color.r > 255 ? 255 : color.r;
	color.g = color.g > 255 ? 255 : color.g;
	color.b = color.b > 255 ? 255 : color.b;
	color.r = color.r < 0 ? 0 : color.r;
	color.g = color.g < 0 ? 0 : color.g;
	color.b = color.b < 0 ? 0 : color.b;
	return (color);
}

/*t_color		multi_l_co(t_prim *prim, t_base base, t_color color, t_i i)
{
	t_vector	v[4];
	t_l_eff		l_e;
	t_color		final;

	final = color_define_value(0, 0, 0);
	inter_p = vec_add(base.ray.origin, vec_mult_d(base.ray.dir, base.tools.t));
	normal = getnm_co(inter_p, prim[base.tools.i].cone, base.ray, base.tools.t);
	direction = nrmz(base.ray.dir);
	while (++i.j < i.nb)
	{
		if (prim[i.j].type == LIGHT)
		{
			half = nrmz(vec_add(vec_mult_d(prim[i.j].light.ray, -1), direction));
			prim[i.j].light.ray = nrmz(vec_sub(prim[i.j].light.src, inter_p));
			l_e.a = ambient_l(direction, normal, 0.5, prim[base.tools.i].type);
			l_e.d = diffuse_l(normal, prim[i.j].light.ray, color, -1.0);
			l_e.s = specular_l(normal, half, prim[i.j].light.color, -1.0);
			if (shadow(prim, i, prim[i.j].light, half) == FALSE)
				final = color_add(final, l_effect(l_e.d, l_e.s, l_e.a, color));
*/
//				ATTENUATION COULEUR MIROIR
			/*if (prim[i.jdx].reflect == TRUE)
			{
				final = color_add_value(final, final.r / -4, final.g / -4,
				final.b / -4);
			}*/
/*		}
	}
	return (cap(final));
}

t_color		multi_l_cy(t_prim *prim, t_base base, t_color color, t_i i)
{
	t_vector	v[4];
	t_l_eff		l_e;
	t_color		final;

	i.j = -1;
	final = color_define_value(0, 0, 0);
	inter_p = vec_add(base.ray.origin, vec_mult_d(base.ray.dir, base.tools.t));
	normal = nrmz(gtnm_cyl(prim[base.tools.i].cyl, inter_p, base.ray, base.tools.t));
	direction = nrmz(base.ray.dir);
	while (++i.j < i.nb)
	{
		if (prim[i.j].type == LIGHT)
		{
			half = nrmz(vec_add(vec_mult_d(prim[i.j].light.ray, -1), direction));
			prim[i.j].light.ray = nrmz(vec_sub(prim[i.j].light.src, inter_p));
			l_e.a = ambient_l(direction, normal, 0.5, prim[base.tools.i].type);
			l_e.d = diffuse_l(normal, prim[i.j].light.ray, color, -1.0);
			l_e.s = specular_l(normal, half, prim[i.j].light.color, -1.0);
			if (shadow(prim, i, prim[i.j].light, half) == FALSE)
				final = color_add(final, l_effect(l_e.d, l_e.s, l_e.a, color));
*/
//				ATTENUATION COULEUR MIROIR
			/*if (prim[i.jdx].reflect == TRUE)
			{
				final = color_add_value(final, final.r / -4, final.g / -4,
				final.b / -4);
			}*/
/*		}
	}
	return (cap(final));
}

t_color		multi_l_s(t_prim *prim, t_base base, t_color color, t_i i)
{
	t_vector	v[4];
	t_l_eff		l_e;
	t_color		final;

	final = color_define_value(0, 0, 0);
	inter_p = vec_add(base.ray.origin, vec_mult_d(base.ray.dir, base.tools.t));
	normal = getnormal_sphere(prim[base.tools.i].sphere, inter_p);
	direction = nrmz(base.ray.dir);
	while (++i.j < i.nb)
	{
		if (prim[i.j].type == LIGHT)
		{
			half = nrmz(vec_add(vec_mult_d(prim[i.j].light.ray, -1), direction));
			prim[i.j].light.ray = nrmz(vec_sub(prim[i.j].light.src, inter_p));
			l_e.a = ambient_l(direction, normal, 0.5, prim[base.tools.i].type);
			l_e.d = diffuse_l(normal, prim[i.j].light.ray, color, -1.0);
			l_e.s = specular_l(normal, half, prim[i.j].light.color, 1.0);
			if (shadow(prim, i, prim[i.j].light, half) == FALSE)
				final = color_add(final, l_effect(l_e.d, l_e.s, l_e.a, color));
*/
//				ATTENUATION COULEUR MIROIR
		/*	if (prim[i.jdx].reflect == TRUE)
			{
				final = color_add_value(final, final.r / -4, final.g / -4,
				final.b / -4);
			}*/
/*		}
	}
	return (cap(final));
}

t_color		multi_l_p(t_prim *prim, t_base base, t_color color, t_i i)
{
	t_vector	normal;
	t_l_eff		l_e;
	t_color		final;

	final = color_define_value(0, 0, 0);
	i.j = -1;
	inter_p = vec_add(base.ray.origin, vec_mult_d(base.ray.dir, base.tools.t));
	direction = nrmz(base.ray.dir);
	while (++i.j < i.nb)
	{
		if (prim[i.j].type == LIGHT)
		{
			half = nrmz(vec_add(vec_mult_d(prim[i.j].light.ray, -1), direction));
			prim[i.j].light.ray = nrmz(vec_sub(inter_p, prim[i.j].light.src));
			l_e.a = ambient_l(direction, prim[base.tools.i].plane.normal, 0.5,
			prim[base.tools.i].type);
			l_e.d = diffuse_l(prim[base.tools.i].plane.normal,
			prim[i.j].light.ray, color, 1.0);
			l_e.s = color_define_value(0, 0, 0);
			if (shadow(prim, i, prim[i.j].light, inter_p) == FALSE)
				final = color_add(final, l_effect(l_e.d, l_e.s, l_e.a, color));
*/
//				ATTENUATION COULEUR MIROIR
			/*if (prim[i.jdx].reflect == TRUE)
			{
				final = color_add_value(final, final.r / -4, final.g / -4,
				final.b / -4);
			}*/
/*		}
	}
	return (cap(final));
}*/

t_l_pack		light_calcul_cone(t_prim *prim, t_base base, t_i i, t_l_pack pack)
{
	// pack.ambient = ambient_l(pack.direction, pack.normal, 0.5);
	pack.diffuse = diffuse_l(pack.normal, prim[i.j].light.ray,
	prim[base.tools.i].cone.color, -1.0);
	pack.specular = specular_l(pack.normal, pack.half, prim[i.j].light.color,
	-1.0);
	return (pack);
}

t_l_pack		light_calcul_cylinder(t_prim *prim, t_base base, t_i i, t_l_pack pack)
{
	// pack.ambient = ambient_l(pack.direction, pack.normal, 0.5);
	pack.diffuse = diffuse_l(pack.normal, prim[i.j].light.ray,
	prim[base.tools.i].cyl.color, -1.0);
	pack.specular = specular_l(pack.normal, pack.half, prim[i.j].light.color,
	-1.0);
	return (pack);
}

t_l_pack		light_calcul_plane(t_prim *prim, t_base base, t_i i, t_l_pack pack)
{
	// pack.ambient = ambient_l(pack.direction, pack.normal, 0.5);
	pack.diffuse = diffuse_l(pack.normal, prim[i.j].light.ray,
	prim[base.tools.i].plane.color, 1.0);
	pack.specular = color_define_value(0, 0, 0);
	// printf("pack plane :\nambient: %lf\ndiffuse: %d %d %d\nspecular: %d %d %d\n", pack.ambient, pack.diffuse.r, pack.diffuse.g, pack.diffuse.b, pack.specular.r, pack.specular.g, pack.specular.b);
	return (pack);
}

t_l_pack		light_calcul_sphere(t_prim *prim, t_base base, t_i i, t_l_pack pack)
{
	// pack.ambient = ambient_l(pack.direction, pack.normal, 0.5);
	pack.diffuse = diffuse_l(pack.normal, prim[i.j].light.ray,
	prim[base.tools.i].sphere.color, -1.0);
	pack.specular = specular_l(pack.normal, pack.half, prim[i.j].light.color,
	1.0);
	return (pack);
}

t_l_pack	light_calcul(t_prim *prim, t_base base, t_i i, t_l_pack pack)
{
	if (prim[base.tools.i].type == SPHERE)
		pack = light_calcul_sphere(prim, base, i, pack);
	else if (prim[base.tools.i].type == PLANE)
		pack = light_calcul_plane(prim, base, i, pack);
	else if (prim[base.tools.i].type == CONE)
		pack = light_calcul_cone(prim, base, i, pack);
	else if (prim[base.tools.i].type == CYLINDER)
		pack = light_calcul_cylinder(prim, base, i, pack);
	return (pack);
}
