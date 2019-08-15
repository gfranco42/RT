/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 10:45:27 by gfranco           #+#    #+#             */
/*   Updated: 2019/08/12 17:48:12 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

int			shadow(t_prim *prim, t_i i, t_base base, t_vector inter_p)
{
	int		t;

	t = 0;
	i.tmp = -1;
	while (++i.tmp < i.nb)
	{
		if (prim[i.tmp].type == SPHERE && t == 0 && base.tools.i != i.tmp)
			t = sphere_light_int(prim[i.tmp].sphere, prim[i.j].light, inter_p);
		else if (prim[i.tmp].type == PLANE && t == 0 && base.tools.i != i.tmp)
			t = plane_light_inter(prim[i.tmp].plane, prim[i.j].light);
		else if (prim[i.tmp].type == CONE && t == 0 && base.tools.i != i.tmp)
			t = cone_light_inter(prim[i.tmp].cone, prim[i.j].light, inter_p);
		else if (prim[i.tmp].type == CYLINDER && t == 0 && base.tools.i != i.tmp)
			t = cyl_light_inter(prim[i.tmp].cyl, prim[i.j].light, inter_p);
	}
	if (t > 0)
		return (TRUE);
	return (FALSE);
}

t_color			first_cap(t_color color)
{
	color.r = color.r > 255 ? 255 : color.r;
	color.g = color.g > 255 ? 255 : color.g;
	color.b = color.b > 255 ? 255 : color.b;
	color.r = color.r < 0 ? 0 : color.r;
	color.g = color.g < 0 ? 0 : color.g;
	color.b = color.b < 0 ? 0 : color.b;
	return (color);
}

/*double		*check_sign(double sign[], t_type type)
{
	sign[0] = -1.0;
	sign[1] = -1.0;
	return (sign);
}*/


t_color		check_shadow(t_prim *prim, t_i i, t_base base, t_color color)
{
	t_l_pack	pack;
	t_color		final;

	final = color_define_value(0, 0, 0);

	pack.inter_p = vec_add(base.ray.origin,
	vec_mult_d(nrmz(base.ray.dir), base.tools.t));

	pack.normal = getnmpri(prim, pack.inter_p, base, base.tools.t);

	pack.direction = nrmz(base.ray.dir);

	i.j = -1;
	while (++i.j < i.nb)
	{
		if (prim[i.j].type == LIGHT)
		{
			pack.half = nrmz(vec_add(vec_mult_d(prim[i.j].light.ray, -1.0),
			pack.direction));
			if (prim[base.tools.i].type != PLANE)
				prim[i.j].light.ray = nrmz(vec_sub(prim[i.j].light.src, pack.inter_p));
			else if (prim[base.tools.i].type == PLANE)
				prim[i.j].light.ray = nrmz(vec_sub(pack.inter_p, prim[i.j].light.src));
			pack = light_calcul(prim, base, i, pack);
			color = color_add(color, pack.diffuse);
			color = color_add(color, pack.specular);
			if (shadow(prim, i, base, pack.inter_p) == FALSE)
				final = color_add(final, color);
		}
	}
	// if (prim[base.tools.i].type == PLANE)
	return (cap(l_scale(final)));
}
//t_color		final_calc(t_l_eff l_e, t_color final, )
