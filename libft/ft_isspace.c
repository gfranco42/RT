/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 16:18:31 by gfranco           #+#    #+#             */
/*   Updated: 2019/03/15 15:46:40 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isspace(int c)
{
	int		result;

	result = 0;
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\r'
	|| c == '\f')
		return (1);
	return (0);
}
