/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_set_poiter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgeorge <xgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 19:02:09 by xgeorge           #+#    #+#             */
/*   Updated: 2020/08/07 07:28:03 by xgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_set_poiter(t_print *obj, void *poiter)
{
	if (obj == NULL)
		return (-1);
	obj->poiter = poiter;
	return (1);
}
