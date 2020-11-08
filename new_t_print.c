/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_t_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgeorge <xgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 18:59:46 by xgeorge           #+#    #+#             */
/*   Updated: 2020/08/07 07:27:26 by xgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print		*new_t_print(void)
{
	t_print	*new;

	if ((new = ft_memalloc(sizeof(t_print))) == NULL)
		return (NULL);
	new->poiter = NULL;
	new->type = ' ';
	new->width = -1;
	new->precision = -1;
	new->printed = NULL;
	new->minus = -1;
	new->plus = -1;
	new->zero = -1;
	new->sign = -1;
	new->white = -1;
	new->len = 0;
	new->len_print = 0;
	return (new);
}
