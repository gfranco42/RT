/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 12:50:52 by gfranco           #+#    #+#             */
/*   Updated: 2019/07/26 12:34:09 by gfranco          ###   ########.fr       */
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
//	printf("normal2   x: %lf, y: %lf, z: %lf\n", nm.x, nm.y, nm.z);
//	printf("2		origin.x: %lf, origin.y: %lf, origin.z: %lf, dir.x: %lf, dir.y: %lf, dir.z: %lf   in:%d\n", base->ray.origin.x, base->ray.origin.y, base->ray.origin.z, base->ray.dir.x, base->ray.dir.y, base->ray.dir.z, base->in);
}
