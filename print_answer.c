/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_answer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgeorge <xgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 19:37:53 by xgeorge           #+#    #+#             */
/*   Updated: 2020/08/07 07:38:36 by xgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					print(t_print *p, int *size)
{
	size_t index;

	index = 0;
	*size = *size + p->len_print;
	if (p->len_print > 0)
	{
		while (index < p->len_print)
		{
			write(1, &(p->printed[index]), 1);
			index++;
		}
	}
	return (1);
}

int					print_answer(int *size, t_dlist **dl_print_object)
{
	t_dlist	*tmp;

	if (dl_print_object == NULL)
		return (-1);
	tmp = *dl_print_object;
	while (tmp->prev != NULL)
		tmp = tmp->prev;
	while (tmp != NULL)
	{
		print(tmp->content, size);
		tmp = tmp->next;
	}
	return (1);
}
