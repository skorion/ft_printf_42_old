/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgeorge <xgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 19:10:56 by xgeorge           #+#    #+#             */
/*   Updated: 2020/08/01 07:50:48 by xgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	get_pp(char *s)
{
	size_t index;

	index = 0;
	while (s[index] != '\0')
	{
		if (s[index] == '.')
			return (index + 1);
		index = index + 1;
	}
	return (0);
}
