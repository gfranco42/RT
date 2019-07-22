/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 12:57:47 by gfranco           #+#    #+#             */
/*   Updated: 2019/07/22 18:21:18 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void		reflect_check(char *line)
{
	if (ft_strcmp(line, "reflect = true") != 0)
	{
		if (ft_strcmp(line, "reflect = false") != 0)
			fail(1);
	}
}

void		refract_check(char *line)
{
	char	**split;

	if (!(split = ft_strsplit(line, ' ')))
		fail(3);
	if (ft_strcmp(split[0], "refract") != 0)
		fail(1);
	if (ft_strcmp(split[1], "=") != 0)
		fail(1);
	if (str_isdouble(split[2]) == 0)
		fail(1);
	if (ft_atoi(split[2]) > 2.0 || ft_atoi(split[2]) < 0.0)
		fail(1);
}
