/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delet_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgeorge <xgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 20:00:41 by xgeorge           #+#    #+#             */
/*   Updated: 2020/08/07 07:37:10 by xgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	kill_print(void *kill_del, size_t size)
{
	if (size != 0)
		print_delet((t_print **)&kill_del);
}

int		delet_all(t_dlist **dl_print_object)
{
	ft_cleardlist(dl_print_object, &kill_print);
	return (1);
}
