/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_data2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 11:42:51 by gfranco           #+#    #+#             */
/*   Updated: 2019/08/02 16:31:40 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

double		vec3_extract_x(char **split, char ***split2)
{
	t_vector	res;

	if (str_isdot(split[0]) == 1)
	{
		if (!(split2[0] = ft_strsplit(split[0], '.')))
			fail(3);
		res.x = get_double(split2[0]);
		free_tab(split2[0], 2);
	}
	else
		res.x = ft_atoi(split[0]);
	return (res.x);
}

double		vec3_extract_y(char **split, char ***split2)
{
	t_vector	res;

	if (str_isdot(split[1]) == 1)
	{
		if (!(split2[1] = ft_strsplit(split[1], '.')))
			fail(3);
		res.y = get_double(split2[1]);
		free_tab(split2[1], 2);
	}
	else
		res.y = ft_atoi(split[1]);
	return (res.y);
}

double		vec3_extract_z(char **split, char ***split2)
{
	t_vector res;

	if (str_isdot(split[2]) == 1)
	{
		if (!(split2[2] = ft_strsplit(split[2], '.')))
			fail(3);
		res.z = get_double(split2[2]);
		free_tab(split2[2], 2);
	}
	else
		res.z = ft_atoi(split[2]);
	return (res.z);
}

double			reflect_extract(int fd)
{
	char	*line;
	char	**split;

	if (get_next_line(fd, &line) <= 0)
		fail(4);
	if (!(split = ft_strsplit(line, ' ')))
		fail(3);
	return (atod(split[2]));
}

double		refract_extract(int fd)
{
	double	res;
	char	*line;
	char	**split;

	if (get_next_line(fd, &line) <= 0)
		fail(4);
	if (!(split = ft_strsplit(line, ' ')))
		fail(3);
	res = atod(split[2]);
	return (res);
}
