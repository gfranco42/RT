/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_prim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 11:19:17 by gfranco           #+#    #+#             */
/*   Updated: 2019/07/19 12:17:11 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void		draw_sphere(t_base base, t_prim *prim, t_mlx mlx, t_i i)
{
	t_vector	inter_p;
	t_l_eff		l_e;

	inter_p = vec_add(base.ray.origin, vec_mult_d(base.ray.dir, base.tools.t));
	l_e.a = ambient_l(nrmz(base.ray.dir),
	getnormal_sphere(prim[base.tools.i].sphere, inter_p), 0.5);
	l_e.effect = multi_l_s(prim, base, prim[base.tools.i].sphere.color, i);
	print_pixel(mlx, base.tools, l_e.effect);
}

void		draw_cyl(t_base base, t_prim *prim, t_mlx mlx, t_i i)
{
	t_vector	inter_p;
	t_l_eff		l_e;

	inter_p = vec_add(base.ray.origin, vec_mult_d(base.ray.dir, base.tools.t));
	l_e.a = ambient_l(nrmz(base.ray.dir),
	nrmz(gtnm_cyl(prim[base.tools.i].cyl, inter_p, base.ray, base.tools.t)),
	-0.5);
	l_e.effect = multi_l_cy(prim, base, prim[base.tools.i].cyl.color, i);
	print_pixel(mlx, base.tools, l_e.effect);
}

void		draw_cone(t_base base, t_prim *prim, t_mlx mlx, t_i i)
{
	t_vector	inter_p;
	t_l_eff		l_e;

	inter_p = vec_add(base.ray.origin, vec_mult_d(base.ray.dir, base.tools.t));
	l_e.a = ambient_l(nrmz(base.ray.dir), getnm_co(inter_p,
	prim[base.tools.i].cone, base.ray, base.tools.t),
	-0.5);
	l_e.effect = multi_l_co(prim, base, prim[base.tools.i].cone.color, i);
	print_pixel(mlx, base.tools, l_e.effect);
}

void	draw_plane(t_base base, t_prim *prim, t_mlx mlx, t_i i)
{
	t_vector	inter_p;
	t_l_eff		l_e;

	inter_p = vec_add(base.ray.origin, vec_mult_d(base.ray.dir, base.tools.t));
	l_e.a = ambient_l(nrmz(base.ray.dir), prim[base.tools.i].plane.normal, 0.5);
	l_e.effect = multi_l_p(prim, base, prim[base.tools.i].plane.color, i);
	print_pixel(mlx, base.tools, l_e.effect);
}
