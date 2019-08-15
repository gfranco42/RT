/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   luminance_alteration.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 18:38:53 by gfranco           #+#    #+#             */
/*   Updated: 2019/08/15 11:32:10 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

/*void		boom(t_base *base, t_prim *prim, t_i *i)
{
	i->ref = -1;
	while (base->tools.t < 200000 && prim[base->tools.i].type != CAMERA
	&& prim[base->tools.i].type != LIGHT && ++i->ref < MAXDEPTH)
	{
		if (prim[base->tools.i].refract >= 1.0)
			reflect_algo(base, prim, i);
		else if (prim[base->tools.i]. >= 1.0)
	}
}*/


t_color			shade(t_base base, t_prim *prim, t_i i, t_color color)
{
	t_color		first_color;
	t_color		reflect_color;
	t_color		refract_color;
	// int			g = 0;
	double		reflect;
	// double		reflect_reverse;
	double		transparence;
	t_vector	inter_p;

	t_color		final_reflect;
	t_color		final_refract;
	t_color		final;
	(void)color;

	first_color = color_define_value(0, 0, 0);
	final = color_define_value(0, 0, 0);
	reflect_color = color_define_value(0, 0, 0);
	refract_color = color_define_value(0, 0, 0);

	i.recu++;
	if (i.recu == 0.0)
		intersect_first(prim, &i, &base);

	if (base.tools.t < MAX_DIST)
	{
		reflect = prim[base.tools.i].reflect;
		transparence = prim[base.tools.i].transparence;
		if (reflect + transparence > 100)
			scale_indices(&reflect, &transparence);
		inter_p = vec_add(base.ray.origin, vec_mult_d(base.ray.dir, base.tools.t));
		base.normal = getnmpri(prim, inter_p, base, base.tools.t);

		// first color******************************
		// recup color obj
		first_color = get_color_prim(prim, base);
		// mult color par ambient
		first_color = color_mult_value(first_color, ambient_l(nrmz(base.ray.dir), base.normal, 0.5));
		// add diffuse && specular
		first_color = check_shadow(prim, i, base, first_color);
		// keep % of light
		first_color = color_mult_value(first_color, (100 - reflect
		- transparence) / 100);

		// reflection*******************************
		//*******************************
		//*******************************
		//*******************************
		//*******************************
		//*******************************
		// BOUCLE INFINIE CHECK LE COMPTEUR i.recu
		//*******************************
		//*******************************
		//*******************************
		//*******************************
		//*******************************
		//*******************************
		// printf();
			if (prim[base.tools.i].reflect > 0.0 && i.recu < MAX_DEPTH)
			{
				reflect_color = reflection(base, prim, i, reflect_color);
				// base.normal = getnmpri(prim, inter_p, base, base.tools.t);
				// calcul new origin && dir
				// compute reflected ray
				// sinon afficher background color
				// else if (base.tools.t >= MAX_DIST)
					// reflect_color = color_define_value(0, 0, 0);
				// *************** calcul theorie *****************
				// first_color = first_color * (100 - (reflect + transparence)) / 100
				// + reflect_color * reflect / 100;
				//*************************************************
				// calcul final color
				// printf("r: %d, g: %d, b: %d, \n", reflect_color.r, reflect_color.g, reflect_color.b);
			}
			// int o = -1;
			if (prim[base.tools.i].refract >= 1.0
			&& prim[base.tools.i].transparence > 0 && i.recu < MAX_DEPTH)
			{
				// printf("aaa\n");
				// printf("%d\n", i.recu);
				refract_color = refraction(base, prim, i, refract_color);
				// inter_refract(prim, i, &base, base.normal);
				// if (base.tools.t < MAX_DIST)
				// {
					// refraction(&base, prim, base.normal, i);
					// inter_refract(prim, i, &base, base.normal);
					// if (base.tools.t < MAX_DIST)
					// {
						// refract_color = get_color_prim(prim, base);
						// refract_color = color_mult_value(refract_color, ambient_l(nrmz(base.ray.dir), base.normal, 0.5));
						// refract_color = check_shadow(prim, i, base, refract_color);
						// refract_color = color_mult_value(refract_color,
						// transparence / 100);
					// }
				// }
				// else if (base.tools.t >= MAX_DIST)
					// refract_color = color_define_value(0, 0, 0);
			}
			final_refract.r = refract_color.r * transparence / 100;
			final_refract.g = refract_color.g * transparence / 100;
			final_refract.b = refract_color.b * transparence / 100;
			final_reflect.r = reflect_color.r * reflect / 100;
			final_reflect.g = reflect_color.g * reflect / 100;
			final_reflect.b = reflect_color.b * reflect / 100;

			// if (reflect > 0)
			// {
				// printf("reflect  r: %dg: %db: %d\n", final_reflect.r, final_reflect.g, final_reflect.b);
				// printf("refract  r: %dg: %db: %d\n", final_refract.r, final_refract.g, final_refract.b);
				// printf("first    r: %dg: %db: %d\n", final_first.r, final_first.g, final_first.b);
			// }
			final.r = first_color.r + final_reflect.r + final_refract.r;
			final.g = first_color.g + final_reflect.g + final_refract.g;
			final.b = first_color.b + final_reflect.b + final_refract.b;
			// final = check_shadow(prim, i, base, final);
			// if (reflect > 0)
				// printf("final    r: %dg: %db: %d\n", final.r, final.g, final.b);
			final = cap(final);
			// first_color = color_add(
					// color_mult_value(first_color, (100 - (reflect + transparence)) / 100),
					// color_mult_value(reflect_color, reflect / 100)
					// );
			// first_color = color_add(
					// first_color,
					// color_mult_value(refract_color, transparence / 100)
					// );
			// first_color = cap(first_color);
	}
	// printf("r: %d, g: %d, b: %d, \n", first_color.r, first_color.g, first_color.b);
	return (final);
}

/*t_color		shade(t_base base, t_prim *prim, t_i i, size_t *recu_depth)
{
	t_color		color;
	t_vector	base.normal;
	int			intersect_flag;

	i.ref = -1;
	(void)recu_depth;
	base.normal = vec_create(0.0, 0.0, 0.0);
	color = color_define_value(0, 0, 0);// changer value par background color
	intersect_flag = FALSE;
	if (*recu_depth == 0)
		intersect_first(prim, &i, &base);
	if (base.tools.t < MAX_DIST)
	{
		color = draw_prim(prim, base, i);
		if (*recu_depth < MAX_DEPTH)
		{
			(*recu_depth)++;
			if (prim[base.tools.i].reflect > 0)
			{
				reflection(&base, prim);
				inter_reflect(prim, &i, &base);
				//color2 = draw_prim(prim, base, i);
				color = color_add(color, shade(base, prim, i, recu_depth));
			}
			if (prim[base.tools.i].refract >= 1.0 && prim[base.tools.i].reflect > 0)
			{
				while (prim[base.tools.i].refract > 0 && ++i.ref < MAX_DEPTH
				&& prim[base.tools.i].transparence > 0)
				{

					refraction(&base, prim, &base.normal);
					inter_refract(prim, &i, &base, base.normal);
				}
				//color2 = draw_prim(prim, base, i);
				color = color_add(color, shade(base, prim, i, recu_depth));
			}
		//	printf("AAA\n");
		}
	}
	return (color);
}*/
