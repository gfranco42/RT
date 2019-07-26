/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 17:20:51 by gfranco           #+#    #+#             */
/*   Updated: 2019/07/23 17:24:35 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_swap_double(double *a, double *b)
{
	double	c;

	c = *a;
	*a = *b;
	*b = c;
}
