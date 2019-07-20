/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 20:00:30 by gfranco           #+#    #+#             */
/*   Updated: 2019/07/18 11:36:19 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void		light_ch(int fd)
{
	int		i;
	char	*line;

	i = -1;
	while (++i < 2)
	{
		if (get_next_line(fd, &line) > 0)
		{
			if (check_vec3(line) == 0)
				fail(1);
		}
		else
			fail(1);
		if (ft_strcmp(line, "") == 0)
			fail(1);
		free(line);
	}
}

void		light_fill(int fd, t_prim *prim, int index)
{
	prim[index].light.src = vec3_extract(fd);
	prim[index].light.color = color_extract(fd);
	prim[index].type = LIGHT;
}
