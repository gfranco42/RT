/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_data3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:03:27 by gfranco           #+#    #+#             */
/*   Updated: 2019/08/02 16:31:51 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

double		transparence_extract(int fd)
{
	char	*line;
	char	**split;

	if (get_next_line(fd, &line) <= 0)
		fail(4);
	if (!(split = ft_strsplit(line, ' ')))
		fail(3);
	return (atod(split[2]));
}
