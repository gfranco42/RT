/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 12:57:47 by gfranco           #+#    #+#             */
/*   Updated: 2019/08/04 14:07:33 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void		reflect_check(char *line)
{
	char	**split;
	double	check;

	if (ft_strcmp(line, "") == 0)
		fail(1);
	if (!(split = ft_strsplit(line, ' ')))
		fail(3);
	if (ft_strcmp(split[0], "reflect") != 0)
		fail(1);
	if (ft_strcmp(split[1], "=") != 0)
		fail(1);
	if (str_isdouble(split[2]) == 0.0)
		fail(1);
	check = atod(split[2]);
	if (check > 100.0 || check < 0)
		fail(1);
}

void		refract_check(char *line)
{
	char	**split;
	double	check;

	if (ft_strcmp(line, "") == 0)
		fail(1);
	if (!(split = ft_strsplit(line, ' ')))
		fail(3);
	if (ft_strcmp(split[0], "refract") != 0)
		fail(1);
	if (ft_strcmp(split[1], "=") != 0)
		fail(1);
	if (str_isdouble(split[2]) == 0)
		fail(1);
	check = atod(split[2]);
	if ((check > 5.13 || check < 1.0) && check != 0.0)
		fail(1);
}

void		transparence_check(char *line)
{
	char	**split;
	double	check;

	if (ft_strcmp(line, "") == 0)
		fail(1);
	if (!(split = ft_strsplit(line, ' ')))
		fail(3);
	if (ft_strcmp(split[0], "transparence") != 0)
		fail(1);
	if (ft_strcmp(split[1], "=") != 0)
		fail(1);
	if (str_isdouble(split[2]) == 0)
		fail(1);
	check = atod(split[2]);
	if (check > 100.0 || check < 0.0)
		fail(1);
}
