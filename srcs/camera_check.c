/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 11:47:51 by gfranco           #+#    #+#             */
/*   Updated: 2019/07/18 11:37:16 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void		camera_ch(int fd)
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
}

void		camera_fill(int fd, t_prim *prim, int index)
{
	prim[index].cam.pos = vec3_extract(fd);
	prim[index].cam.target = vec3_extract(fd);
	prim[index].cam.up = vec3_extract(fd);
	prim[index].cam.up = nrmz(prim[index].cam.up);
	prim[index].type = CAMERA;
}
