/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 19:59:21 by gfranco           #+#    #+#             */
/*   Updated: 2019/07/22 18:47:51 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void		sphere_ch_ext2(int fd, char *line)
{
	if (get_next_line(fd, &line) > 0)
		refract_check(line);
	else
		fail(1);
	if (ft_strcmp(line, "") == 0)
		fail(1);
	free(line);
}

void		sphere_ch_ext(int fd, char *line)
{
	if (ft_strcmp(line, "") == 0)
		fail(1);
	free(line);
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
	if (get_next_line(fd, &line) > 0)
		reflect_check(line);
	else
		fail(1);
	if (ft_strcmp(line, "") == 0)
		fail(1);
	free(line);
	sphere_ch_ext2(fd, line);
}

void		sphere_ch(int fd)
{
	int		i;
	char	*line;

	i = -1;
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
	if (get_next_line(fd, &line) > 0)
	{
		if (str_isdigit(line) == 0)
			fail(1);
	}
	else
		fail(1);
	sphere_ch_ext(fd, line);
}

void		sphere_fill(int fd, t_prim *prim, int index)
{
	prim[index].sphere.center = vec3_extract(fd);
	prim[index].sphere.radius = double_extract(fd);
	prim[index].sphere.color = color_extract(fd);
	prim[index].sphere.color = first_cap(prim[index].sphere.color);
	prim[index].reflect = reflect_extract(fd);
	prim[index].refract = refract_extract(fd);
	prim[index].type = SPHERE;
}
