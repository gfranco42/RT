/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 14:40:24 by gfranco           #+#    #+#             */
/*   Updated: 2019/08/14 15:18:42 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_color		reflection(t_base base, t_prim *prim, t_i i, t_color reflect_color)
{
	double		reflect;
	t_vector	inter_p;

	reflect = prim[base.tools.i].reflect;
	inter_p = vec_add(base.ray.origin, vec_mult_d(base.ray.dir, base.tools.t));
	base.ray.origin = vec_add_double(inter_p, 0.0);
/*	base.ray.origin.x = inter_p.x;
	base.ray.origin.y = inter_p.y;
	base.ray.origin.z = inter_p.z;*/
	// normal = getnmpri(prim, base.ray.origin, *base, base.tools.t);
	base.ray.dir.x = base.ray.dir.x - 2 * dot(base.normal, base.ray.dir)
	* base.normal.x;
	base.ray.dir.y = base.ray.dir.y - 2 * dot(base.normal, base.ray.dir)
	* base.normal.y;
	base.ray.dir.z = base.ray.dir.z - 2 * dot(base.normal, base.ray.dir)
	* base.normal.z;
	base.ray.dir = nrmz(base.ray.dir);
	inter_reflect(prim, i, &base);
	// si intersection == TRUE
	if (base.tools.t < MAX_DIST)
	{
		// recup color obj
		// reflect_color = get_color_prim(prim, base);
		// mult color par ambient
		// reflect_color = color_mult_value(reflect_color,
		// ambient_l(nrmz(base.ray.dir), base.normal, 0.5));
		// add diffuse && specular
		// reflect_color = check_shadow(prim, i, base, reflect_color);
		// keep % light
		// reflect_color = color_mult_value(reflect_color,
		// reflect / 100);
		reflect_color = shade(base, prim, i, reflect_color);
	}
	else
		reflect_color = color_define_value(0, 0, 0);
	return (reflect_color);
}

/*void		reflect_algo(t_base *base, t_prim *prim, t_i *i)
{
	i.ref = -1;
	while (base.tools.t < 200000 && prim[base.tools.i].type != CAMERA
	&& prim[base.tools.i].type != LIGHT && ++i.ref < MAX_DEPTH && prim[base.tools.i].reflect > 0)
	{
		reflection(base, prim, *i);
	//	printf("i.ref: %d\n", i.ref);
	}
	base.tools.n1 = 1.0;
	//printf("AAAAA\n");
}*/
