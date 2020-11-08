/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_set_printed.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgeorge <xgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 19:02:34 by xgeorge           #+#    #+#             */
/*   Updated: 2020/07/21 19:02:35 by xgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_set_printed(t_print *obj, char *printed)
{
	if (obj == NULL)
		return (-1);
	obj->printed = printed;
	return (1);
}
