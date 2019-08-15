/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_prim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 11:19:17 by gfranco           #+#    #+#             */
/*   Updated: 2019/08/06 16:32:47 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_color		draw_sphere(t_base base, t_prim *prim, t_i i)
{
	t_vector	inter_p;
	t_l_eff		l_e;

	i.j = -1;
	inter_p = vec_add(base.ray.origin, vec_mult_d(base.ray.dir, base.tools.t));
	l_e.a = ambient_l(nrmz(base.ray.dir),
	getnormal_sphere(prim[base.tools.i].sphere, inter_p), 0.5
	);
	l_e.effect = color_define_value(0, 0, 0);//  multi_l_s(prim, base, prim[base.tools.i].sphere.color, i);
	return (l_e.effect);
}

t_color		draw_cyl(t_base base, t_prim *prim, t_i i)
{
	t_vector	inter_p;
	t_l_eff		l_e;

	i.j = -1;
	inter_p = vec_add(base.ray.origin, vec_mult_d(base.ray.dir, base.tools.t));
	l_e.a = ambient_l(nrmz(base.ray.dir),
	nrmz(gtnm_cyl(prim[base.tools.i].cyl, inter_p, base.ray, base.tools.t)),
	-0.5 );
	l_e.effect = color_define_value(0, 0, 0);// multi_l_cy(prim, base, prim[base.tools.i].cyl.color, i);
	return (l_e.effect);
}

t_color		draw_cone(t_base base, t_prim *prim, t_i i)
{
	t_vector	inter_p;
	t_l_eff		l_e;

	i.j = -1;
	inter_p = vec_add(base.ray.origin, vec_mult_d(base.ray.dir, base.tools.t));
	l_e.a = ambient_l(nrmz(base.ray.dir), getnm_co(inter_p,
	prim[base.tools.i].cone, base.ray, base.tools.t),
	-0.5 );
	l_e.effect = color_define_value(0, 0, 0);// multi_l_co(prim, base, prim[base.tools.i].cone.color, i);
	return (l_e.effect);
}

t_color		draw_plane(t_base base, t_prim *prim, t_i i)
{
	t_vector	inter_p;
	t_l_eff		l_e;

	i.j = -1;
	inter_p = vec_add(base.ray.origin, vec_mult_d(base.ray.dir, base.tools.t));
	l_e.a = ambient_l(nrmz(base.ray.dir), prim[base.tools.i].plane.normal, 0.5
	);
	l_e.effect = color_define_value(0, 0, 0);// multi_l_p(prim, base, prim[base.tools.i].plane.color, i);
	return (l_e.effect);
}

t_color		draw_prim(t_prim *prim, t_base base, t_i i)
{
	t_color		color;

	color = color_define_value(0, 0, 0);
	if ( prim[base.tools.i].type== SPHERE)
		color = draw_sphere(base, prim, i);
	else if ( prim[base.tools.i].type== PLANE)
		color = draw_plane(base, prim, i);
	else if ( prim[base.tools.i].type== CONE)
		color = draw_cone(base, prim, i);
	else if ( prim[base.tools.i].type== CYLINDER)
		color = draw_cyl(base, prim, i);
	/*else
	{
		(void)prim;
		(void)base;

		(void)i;
	}*/

	return (color);
}
