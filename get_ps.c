/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ps.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgeorge <xgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 19:11:24 by xgeorge           #+#    #+#             */
/*   Updated: 2020/07/21 19:11:33 by xgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	get_ps(char *s)
{
	size_t index;

	index = 0;
	while (s[index] != '\0')
	{
		if (s[index] == 'l' || s[index] == 'L' || s[index] == 'h')
			return (index);
		index = index + 1;
	}
	return (0);
}
