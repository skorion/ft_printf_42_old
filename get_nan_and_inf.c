/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nan_and_inf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgeorge <xgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 02:18:12 by xgeorge           #+#    #+#             */
/*   Updated: 2020/08/07 04:34:39 by xgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_nan_and_inf(long double num, char znak)
{
	if (num != num)
		return (ft_strdup("nan\0"));
	if (num == (-1 * INFINITY) || (num == INFINITY && znak == '-'))
		return (ft_strdup("-inf\0"));
	if (num == (INFINITY))
	{
		if (znak == ' ')
			return (ft_strdup(" inf\0"));
		if (znak == '+')
			return (ft_strdup("+inf\0"));
		return (ft_strdup("inf\0"));
	}
	return (NULL);
}
