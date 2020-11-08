/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgeorge <xgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 03:00:22 by xgeorge           #+#    #+#             */
/*   Updated: 2020/08/07 07:35:43 by xgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_u_sta(t_print *print, va_list list_param, unsigned int long long *l)
{
	set_stars(print, list_param);
	ft_strdel(&(print->printed));
	if (print->minus == 1 && print->zero == 1)
		print->zero = 0;
	if (print->zero == 1 && print->precision == -1)
		print->precision = print->width;
	if (print->len == 0)
		*l = va_arg(list_param, unsigned int);
	if (print->len == 1)
		*l = (unsigned short)va_arg(list_param, unsigned int);
	if (print->len == 2)
		*l = (unsigned char)va_arg(list_param, unsigned int);
	if (print->len == 3)
		*l = va_arg(list_param, unsigned long int);
	if (print->len == 4 || print->len == 5)
		*l = va_arg(list_param, unsigned long long int);
}

int		get_unsig_numlen(unsigned int long long l)
{
	int len;

	len = 0;
	while (l >= 10)
	{
		l = l / 10;
		len = len + 1;
	}
	return (len + 1);
}

char	*itoaunsig(unsigned int long long l, int prec)
{
	int		len;
	char	*ans;

	if (!(l == 0 && prec == 0))
	{
		len = get_unsig_numlen(l);
		len = (len < prec) ? (prec) : (len);
		if ((ans = ft_strnew(len)) == NULL)
			return (NULL);
		ft_memset(ans, '0', len);
		while (l >= 10)
		{
			ans[len - 1] = '0' + (int)(l % 10);
			l = l / 10;
			len--;
		}
		ans[len - 1] = '0' + (int)(l % 10);
	}
	else
		return (ft_strnew(1));
	return (ans);
}

int		format_u(t_print *print, va_list list_param)
{
	unsigned int long long	l;
	char					*number;
	size_t					len;
	size_t					start_pos;

	set_u_sta(print, list_param, &l);
	print->printed = NULL;
	print->len_print = 0;
	if (!(number = itoaunsig(l, print->precision)))
		return (-1);
	len = ft_strlen(number);
	print->len_print = (print->width > 0) ? print->width : 0;
	print->len_print = (print->len_print > len) ? print->len_print : len;
	if (!(print->printed = ft_strnew(print->len_print)))
	{
		ft_strdel(&number);
		print->len_print = 0;
		print->printed = NULL;
		return (-1);
	}
	ft_memset(print->printed, ' ', print->len_print);
	start_pos = (print->minus == 1) ? 0 : print->len_print - len;
	ft_strncpy(&(print->printed[start_pos]), number, len);
	ft_strdel(&number);
	return (0);
}
