/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgeorge <xgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 00:37:20 by xgeorge           #+#    #+#             */
/*   Updated: 2020/08/07 07:19:42 by xgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pars_and_formating(t_print *print, va_list list_param)
{
	pars(print);
	if (ft_strlen(print->printed) == 1)
	{
		print->type = 'j';
		print->len_print = 0;
	}
	formating(print, list_param);
}

int		we_add_string_in_print(
		t_dlist **dl_print_object, char *format, size_t start, size_t end)
{
	char *poiter;
	char *printed;

	if (make_dlist_with_new_print(dl_print_object) == -1)
		return (-1);
	print_set_type((t_print*)(*dl_print_object)->content, 'j');
	if ((poiter = ft_strsub(format, start, end - start)) == NULL)
		return (-1);
	print_set_poiter((t_print*)(*dl_print_object)->content, poiter);
	if ((printed = ft_strdup(poiter)) == NULL)
		return (-1);
	print_set_printed((t_print*)(*dl_print_object)->content, printed);
	set_len_print((t_print*)(*dl_print_object)->content);
	return (1);
}

int		add_param(
		t_dlist **dl_print_object, va_list list_param, char *format, size_t end)
{
	char *printed;

	if (make_dlist_with_new_print(dl_print_object) == -1)
		return (-1);
	print_set_type((t_print*)(*dl_print_object)->content, format[end]);
	if (!(printed = ft_strsub(format, 0, end + 1)))
		return (-1);
	print_set_printed((t_print*)(*dl_print_object)->content, printed);
	pars_and_formating((t_print*)(*dl_print_object)->content, list_param);
	return (1);
}

void	init_read_all(size_t *start, size_t *end, int *stage)
{
	*start = 0;
	*end = 0;
	*stage = 1;
}

int		read_all(char *format, t_dlist **dl_print, va_list param)
{
	size_t	start;
	size_t	end;
	int		stage;

	init_read_all(&start, &end, &stage);
	while (stage != 0)
	{
		if (stage == 1)
		{
			end = get_next_end_or_param(format, start);
			if (we_add_string_in_print(dl_print, format, start, end) == -1)
				return (-1);
			start = end;
			stage = (format[end] == '%') ? 2 : 0;
		}
		if (stage == 2)
		{
			end = get_next_symbol_type(format, start);
			if (add_param(dl_print, param, &(format[start]), end - start) == -1)
				return (-1);
			start = end + 1;
			stage = (format[end] == '\0') ? 0 : 1;
		}
	}
	return (1);
}
