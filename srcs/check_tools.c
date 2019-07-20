/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 12:57:47 by gfranco           #+#    #+#             */
/*   Updated: 2019/07/20 13:28:00 by gfranco          ###   ########.fr       */
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
