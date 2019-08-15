/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 15:50:07 by gfranco           #+#    #+#             */
/*   Updated: 2019/08/12 17:51:34 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

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

void		rein_value_ma(t_base *base, t_i *i, t_prim *prim)
{
	base->tools.t = MAX_DIST;
	i->dbl = MAX_DIST;
	base->ray.origin = vec_add_double(prim[i->cm].cam.pos, 0);
}

void		main_algo(t_base base, t_prim *prim, t_mlx mlx, t_i i)
{
	t_color		color;
	t_color		background;
	// t_vector	inter_p;
	// t_vector	normal;
	// double		ambient;

	base.in = FALSE;
	base.tools.y = -1;
	background = color_define_value(0, 0, 0);
	while (++base.tools.y < HEIGHT)
	{
		base.tools.x = -1;
		while (++base.tools.x < WIDTH)
		{
			rein_value_ma(&base, &i, prim);
			calc_dir(base.upleft, &base);
			i.recu = -1.0;
			color = shade(base, prim, i, background);
			// intersect_first(prim, &i, &base);
			// if (base.tools.t < MAX_DIST)
			// {
			// color = get_color_prim(prim, base);
			// inter_p = vec_add(base.ray.origin, vec_mult_d(base.ray.dir, base.tools.t));
			// normal = getnmpri(prim, inter_p, base, base.tools.t);
			// printf("%lf\n", ambient);
			// printf("r: %d, g: %d, b: %d, \n", color.r, color.g, color.b);
			// color = check_shadow(prim, i, base, color);
			// color = color_mult_value(color, (100 - (prim[base.tools.i].reflect
			// + prim[base.tools.i].transparence)) / 100);
			//printf("r: %d, g: %d, b: %d, \n", color.r, color.g, color.b);
			// if ((prim[base.tools.i].refract >= 1.0
			// && prim[base.tools.i].transparence > 0.0)
			// || prim[base.tools.i].reflect > 0.0)
		//	printf("recu: %zu\n", recu_depth);
			//color = color_div_value(color, recu_depth);
		//	intersect_first(prim, &i, &base);
		//	refract_algo(&base, &i, prim);
		//	printf("%lf %lf\n", base.tools.n1, base.tools.n2);

//				ATTENUATION COULEUR MIROIR
//			i.idx = base.tools.i;
		//	reflect_algo(&base, prim, &i);
		/*	if (base.tools.t < MAX_DIST)
				color = draw_prim(prim, base, i);*/
			// color = l_effect(color);
			//color = cap(color);
		//	printf("r %d g %d b %d \n", color.r, color.g, color.b);
			print_pixel(mlx, base.tools, color);
			// printf("%d\n", base.tools.y);
		}
	}
	free(prim);
}

/*
	pour attenuation couleur miroir:
	enlever commentaires fichier " multi_light_calculation.c "
*/
