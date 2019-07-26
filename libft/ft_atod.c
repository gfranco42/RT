/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 13:13:21 by gfranco           #+#    #+#             */
/*   Updated: 2019/07/23 13:13:51 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		atod(char *str)
{
	double	res;
	char	**split;

	if (str_isdot(str) == 1)
	{
		if (!(split = ft_strsplit(str, '.')))
			fail(3);
		res = get_double(split);
		free_tab(split, 2);
	}
	else
	{
		res = ft_atoi(str);
		(void)split;
	}
	free(str);
	return (res);
}
