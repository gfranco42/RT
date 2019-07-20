/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 19:59:41 by gfranco           #+#    #+#             */
/*   Updated: 2019/07/20 14:09:25 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void		plane_ch(int fd)
{
	int		i;
	char	*line;

	i = -1;
	while (++i < 3)
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
	if (get_next_line(fd, &line) > 0)
		reflect_check(line);
	else
		fail(1);
	if (ft_strcmp(line, "") == 0)
		fail(1);
	free(line);
}

void		plane_fill(int fd, t_prim *prim, int index)
{
	prim[index].plane.point = vec3_extract(fd);
	prim[index].plane.normal = vec3_extract(fd);
	prim[index].plane.normal = nrmz(prim[index].plane.normal);
	prim[index].plane.color = color_extract(fd);
	prim[index].plane.color = first_cap(prim[index].plane.color);
	prim[index].reflect = reflect_extract(fd);
	prim[index].type = PLANE;
}
