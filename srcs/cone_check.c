/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 20:00:06 by gfranco           #+#    #+#             */
/*   Updated: 2019/07/20 14:06:36 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void		cone_ch_ext(int fd, char *line)
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

void		cone_ch(int fd)
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
	cone_ch_ext(fd, line);
}

void		cone_fill(int fd, t_prim *prim, int index)
{
	prim[index].cone.tip = vec3_extract(fd);
	prim[index].cone.dir = vec3_extract(fd);
	prim[index].cone.dir = nrmz(prim[index].cone.dir);
	prim[index].cone.color = color_extract(fd);
	prim[index].cone.color = first_cap(prim[index].cone.color);
	prim[index].cone.angle = double_extract(fd);
	prim[index].reflect = reflect_extract(fd);
	prim[index].type = CONE;
}
