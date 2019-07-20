/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 20:00:22 by gfranco           #+#    #+#             */
/*   Updated: 2019/07/20 14:06:50 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void		cylinder_ch_ext(int fd, char *line)
{
	if (ft_strcmp(line, "") == 0)
		fail(1);
	free(line);
	if (get_next_line(fd, &line) > 0)
		reflect_check(line);
	else
		fail(1);
	if (ft_strcmp(line, "") == 0)
		fail(1);
	free(line);
}

void		cylinder_ch(int fd)
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
	{
		if (str_isdouble(line) == 0)
			fail(1);
	}
	else
		fail(1);
	cylinder_ch_ext(fd, line);
}

void		cylinder_fill(int fd, t_prim *prim, int index)
{
	prim[index].cyl.center = vec3_extract(fd);
	prim[index].cyl.dir = vec3_extract(fd);
	prim[index].cyl.dir = nrmz(prim[index].cyl.dir);
	prim[index].cyl.color = color_extract(fd);
	prim[index].cyl.color = first_cap(prim[index].cyl.color);
	prim[index].cyl.radius = double_extract(fd);
	prim[index].reflect = reflect_extract(fd);
	prim[index].type = CYLINDER;
}
