/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgeorge <xgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 19:10:24 by xgeorge           #+#    #+#             */
/*   Updated: 2020/07/21 19:10:44 by xgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	get_pw(char *s)
{
	size_t index;

	index = 0;
	while (s[index] != '\0')
	{
		if (s[index] == '.')
			return (0);
		if ((ft_isdigit(s[index]) && s[index] != '0') || s[index] == '*')
			return (index);
		index = index + 1;
	}
	return (0);
}
