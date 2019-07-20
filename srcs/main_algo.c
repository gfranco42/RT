/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 15:50:07 by gfranco           #+#    #+#             */
/*   Updated: 2019/07/20 19:22:06 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void		draw_prim(t_prim *prim, t_base base, t_mlx mlx, t_i i)
{
	if (prim[base.tools.i].type == SPHERE)
		draw_sphere(base, prim, mlx, i);
	if (prim[base.tools.i].type == PLANE)
		draw_plane(base, prim, mlx, i);
	if (prim[base.tools.i].type == CONE)
		draw_cone(base, prim, mlx, i);
	if (prim[base.tools.i].type == CYLINDER)
		draw_cyl(base, prim, mlx, i);
}

void		calc_dir(t_vector upleft, t_base *base)
{
	base->ray.dir.x = upleft.x + base->cam.right.x * base->cam.w_view /
	(double)WIDTH * base->tools.x - base->cam.vertical.x * base->cam.h_view /
	(double)HEIGHT * base->tools.y;
	base->ray.dir.y = upleft.y + base->cam.right.y * base->cam.w_view /
	(double)WIDTH * base->tools.x - base->cam.vertical.y * base->cam.h_view /
	(double)HEIGHT * base->tools.y;
	base->ray.dir.z = upleft.z + base->cam.right.z * base->cam.w_view /
	(double)WIDTH * base->tools.x - base->cam.vertical.z * base->cam.h_view /
	(double)HEIGHT * base->tools.y;
	base->ray.dir = nrmz(base->ray.dir);
}


void		main_algo(t_base base, t_prim *prim, t_mlx mlx, t_i i)
{
	base.tools.y = -1;
	while (++base.tools.y < HEIGHT)
	{
		base.tools.x = -1;
		while (++base.tools.x < WIDTH)
		{
			i.ref = -1;
			base.tools.t = 200000.0;
			i.dbl = 200000.0;
			base.ray.origin = vec_add_double(prim[i.cm].cam.pos, 0);
			calc_dir(base.upleft, &base);
			intersect_first(prim, &i, &base);
			while (base.tools.t < 200000 && prim[base.tools.i].type != CAMERA &&
			prim[base.tools.i].type != LIGHT && prim[base.tools.i].reflect == 1 && ++i.ref < MAXDEPTH)
			{
				reflection(base.tools.t, &base, prim);
				intersect(prim, &i, &base);
			}
			i.j = -1;
			if (base.tools.t < 200000)
				draw_prim(prim, base, mlx, i);
		}
	}
	//printf("x: %lf y: %lf z: %lf", inter_p.x,  inter_p.y, inter_p.z);
	free(prim);
}
