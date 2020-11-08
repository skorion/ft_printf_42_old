/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_dlist_with_new_print.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgeorge <xgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 01:39:44 by xgeorge           #+#    #+#             */
/*   Updated: 2020/08/07 07:28:14 by xgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		make_dlist_with_new_print(t_dlist **list)
{
	t_print		*new;
	t_dlist		*dist;

	if ((new = new_t_print()) == NULL)
		return (-1);
	if ((dist = ft_newdlist(new, sizeof(t_print))) == NULL)
	{
		print_delet(&new);
		return (-1);
	}
	free(new);
	*list = ft_addenddlist(list, dist);
	while ((*list)->next != NULL)
		*list = (*list)->next;
	return (1);
}
