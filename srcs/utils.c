/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 12:50:52 by gfranco           #+#    #+#             */
/*   Updated: 2019/08/13 16:22:58 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

double		atod(char *str)
{
	double	res;
	char	**split;

	if (str_isdot(str) == 1)
	{
		if (!(split = ft_strsplit(str, '.')))
			fail(3);
		res = get_double(split);
		free_tab(split, 2);
	}
	else
	{
		res = ft_atoi(str);
		(void)split;
	}
	free(str);
	return (res);
}

int			is_prim(t_prim *prim, t_base base)
{
	if (prim[base.tools.i].type != CAMERA && prim[base.tools.i].type != LIGHT)
		return (TRUE);
	return (FALSE);
}

double		clamp(int i, int j, double dot)
{
	if (dot < i)
		dot = i;
	else if (dot > j)
		dot = j;
	return (dot);
}

void		move_origin(t_base *base, t_vector nm)
{
//	printf("1		origin.x: %lf, origin.y: %lf, origin.z: %lf, dir.x: %lf, dir.y: %lf, dir.z: %lf   in:%d\n", base->ray.origin.x, base->ray.origin.y, base->ray.origin.z, base->ray.dir.x, base->ray.dir.y, base->ray.dir.z, base->in);
//	printf("normal1   x: %lf, y: %lf, z: %lf\n", nm.x, nm.y, nm.z);
	nm = vec_mult_d(nm, -0.1);
	if (base->in == FALSE)
		base->ray.origin = vec_add(base->ray.origin, nm);
	else
		base->ray.origin = vec_sub(base->ray.origin, nm);
	//printf("normal2   x: %lf, y: %lf, z: %lf\n", nm.x, nm.y, nm.z);
//	printf("2		origin.x: %lf, origin.y: %lf, origin.z: %lf, dir.x: %lf, dir.y: %lf, dir.z: %lf   in:%d\n", base->ray.origin.x, base->ray.origin.y, base->ray.origin.z, base->ray.dir.x, base->ray.dir.y, base->ray.dir.z, base->in);
}

t_color		get_color_prim(t_prim *prim, t_base base)
{
	if (prim[base.tools.i].type == SPHERE)
		return (prim[base.tools.i].sphere.color);
	else if (prim[base.tools.i].type == CYLINDER)
		return (prim[base.tools.i].cyl.color);
	else if (prim[base.tools.i].type == PLANE)
		return (prim[base.tools.i].plane.color);
	else
	{
		// printf("cone r %d g %d b %d\n", prim[base.tools.i].cone.color.r, prim[base.tools.i].cone.color.g, prim[base.tools.i].cone.color.b);
		return (prim[base.tools.i].cone.color);
	}
}

t_color		new_scale(t_color effect)
{
	int		total;

	total = effect.r + effect.g + effect.b;
	// printf("total: %d\n", total);
	// printf("r: %d, g: %d, b: %d, \n", effect.r, effect.g, effect.b);
	if (total > 0)
	{

		effect.r = effect.r * 255 / total;
		effect.g = effect.g * 255 / total;
		effect.b = effect.b * 255 / total;
	}
	return (effect);
}

void		scale_indices(double *reflect, double *transparence)
{
	double		total;

	total = *reflect + *transparence;
	*reflect *= 100 / total;
	*transparence *= 100 / total;
}
