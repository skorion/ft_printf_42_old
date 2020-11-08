/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_delet.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgeorge <xgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 19:00:40 by xgeorge           #+#    #+#             */
/*   Updated: 2020/08/07 07:24:38 by xgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_delet(t_print **obj)
{
	if (obj == NULL)
		return (-1);
	if ((*obj) == NULL)
		return (-1);
	if ((*obj)->poiter)
	{
		if ((*obj)->type == 'j')
		{
			free((*obj)->poiter);
			(*obj)->poiter = NULL;
		}
	}
	if ((*obj)->printed)
	{
		free((*obj)->printed);
		(*obj)->printed = NULL;
	}
	free(*obj);
	*obj = NULL;
	return (1);
}
