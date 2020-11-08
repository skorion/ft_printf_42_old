/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_set_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgeorge <xgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 19:01:34 by xgeorge           #+#    #+#             */
/*   Updated: 2020/08/07 07:22:42 by xgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_set_type(t_print *obj, char c)
{
	if (obj == NULL)
		return (-1);
	obj->type = c;
	return (1);
}