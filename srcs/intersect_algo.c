/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 16:15:18 by gfranco           #+#    #+#             */
/*   Updated: 2019/07/26 12:36:22 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	get_tools_value(t_base *base, t_i i)
{
	base->tools.t = i.tmp;
	base->tools.i = i.i;
}

double		intersect_prim_first(t_prim *prim, int i, t_base base)
{

	if (prim[i].type == SPHERE)
		base.tools.t = sphere_intersect(prim[i].sphere, base.ray, base.tools.t);
	else if (prim[i].type == PLANE)
		base.tools.t = plane_intersect(prim[i].plane, base.ray, base.tools.t);
	else if (prim[i].type == CONE)
		base.tools.t = cone_intersect(prim[i].cone, base.ray, base.tools.t);
	else if (prim[i].type == CYLINDER)
		base.tools.t = cylinder_intersect(prim[i].cyl, base.ray, base.tools.t);
	return (base.tools.t);
}

//			renvoie la distance et l'index de l'objet qui a une intersection
//			premiere intersection a partir de la camera
void		intersect_first(t_prim *prim, t_i *i, t_base *base)
{
	base->in = FALSE;
	i->dbl = 200000;
	base->tools.t = 200000;
	i->i = -1;
	//		i->i cherche l'objet
	//		base.tools.i == l'objet en cours d'avant
	while(++i->i < i->nb)
	{
		i->dbl = intersect_prim_first(prim, i->i, *base);
		if (i->dbl < base->tools.t)
		{
			base->tools.t = i->dbl;
			base->tools.i = i->i;
		}
	}
//	printf("%lf, %d\n", base->tools.t, base->tools.i);
	// premierlancer de rayon depuis la cam:
	// n1 = air
	// n2 = indice de l'objet qu'on vient d'intersecter
	//print("t AVANT intersect: %lf\nl'index: %d\n", base->tools.t, base->tools.i);
	if (is_prim(prim, *base) == TRUE && prim[base->tools.i].refract > 0)
	{
		base->tools.n1 = 1.0;
		base->tools.n2 = prim[base->tools.i].refract;
		base->in = TRUE;
	//	printf("1   %lf %lf\n", base->tools.n1, base->tools.n2);
	}
//	printf("n2: %lf\n", base->tools.n2);
//	printf("n2: %lf\n", base->tools.n2);
}

double		intersect_prim(t_prim *prim, t_i i, t_base base)
{

	if (prim[i.i].type == SPHERE)
		base.tools.t = sphere_intersect(prim[i.i].sphere, base.ray, base.tools.t);
	else if (prim[i.i].type == PLANE)
		base.tools.t = plane_intersect(prim[i.i].plane, base.ray, base.tools.t);
	else if (prim[i.i].type == CONE)
		base.tools.t = cone_intersect(prim[i.i].cone, base.ray, base.tools.t);
	else if (prim[i.i].type == CYLINDER)
		base.tools.t = cylinder_intersect(prim[i.i].cyl, base.ray, base.tools.t);
	return (base.tools.t);
}

//			renvoie la distance et l'index de l'objet qui a une intersection
void		intersect(t_prim *prim, t_i *i, t_base *base, t_vector normal)
{
	int		tmp;

	tmp = base->tools.i;
	base->tools.t = 200000;
	i->i = -1;
	while (++i->i < i->nb)
	{
		while ((i->dbl = intersect_prim_first(prim, i->i, *base)) <= 0.0)
			move_origin(base, normal);
		if (i->dbl < base->tools.t)
		{
			base->tools.t = i->dbl;
			base->tools.i = i->i;
		}
	}
	if (base->tools.i == tmp)
		base->in = FALSE;
	else if  (base->tools.i != tmp && prim[base->tools.i].refract > 0.0)
		base->in = TRUE;
//	printf("t:											%lf\n", base->tools.t);
	//if (base->in == FALSE)
//	printf("4  %d\n", base->in);
	/*if (base->tools.i == tmp && base->tools.t < 200000.0)
	{
		base->tools.n1 = base->tools.n2;
		base->tools.n2 = 1.0;*/
	//	printf("2   %lf %lf\n", base->tools.n1, base->tools.n2);
	/*}
	else
	{
		base->tools.n1 = base->tools.n2;
		base->tools.n2 = prim[base->tools.i].refract;*/
	//	printf("3   %lf %lf\n", base->tools.n1, base->tools.n2);
	//}

//	if (base->in == FALSE)
//	printf("5  %d\n", base->in);
//	if (prim[f].type == SPHERE)
//		printf("f: %d base: %d\n", f, base->tools.i);
	//if (base->in == FALSE)
//	printf("6  %d\n", base->in);
//	printf("7 : %lf, before: %d, after: %d\n", base->tools.t, tmp, base->tools.i);
	//if (prim[base->tools.i].type == PLANE)
	//	printf("1  %lf %lf\n", base->tools.n1, base->tools.n2);
}
