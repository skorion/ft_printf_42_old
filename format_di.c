/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_di.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgeorge <xgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 02:58:37 by xgeorge           #+#    #+#             */
/*   Updated: 2020/08/07 03:04:27 by xgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_numlen_with_only_digit(int long long num)
{
	int	len;

	len = 0;
	while (num >= 10 || num <= -10)
	{
		num = num / 10;
		len++;
	}
	return (len + 1);
}

char	*itoa_only_digit(int long long num, char sign, int p)
{
	char	*ans;
	int		len;

	len = get_numlen_with_only_digit(num);
	len = (p > len) ? p : len;
	len = (sign != '?') ? len + 1 : len;
	if ((ans = ft_strnew(len)) == NULL)
		return (NULL);
	ft_memset(ans, '0', len);
	if (sign != '?')
	{
		ans[0] = sign;
	}
	while (num >= 10 || num <= -10)
	{
		ans[len - 1] = '0' + (int)(num < 0 ? -1 : 1) *
									(num - ((num / 10) * 10));
		num = num / 10;
		len--;
	}
	ans[len - 1] = '0' + (int)(num < 0 ? -1 : 1) *
									(num - ((num / 10) * 10));
	return (ans);
}

void	set_start(t_print *print, va_list list_param, long long *l)
{
	set_stars(print, list_param);
	ft_strdel(&(print->printed));
	if (print->plus == 1 && print->white == 1)
		print->white = 0;
	if (print->minus == 1 && print->zero == 1)
		print->zero = 0;
	if (print->len == 0)
		*l = va_arg(list_param, int);
	if (print->len == 1)
		*l = (short)va_arg(list_param, int);
	if (print->len == 2)
		*l = (char)va_arg(list_param, int);
	if (print->len == 3)
		*l = va_arg(list_param, long int);
	if (print->len == 4 || print->len == 5)
		*l = va_arg(list_param, long long int);
}

int		set_znak(t_print *print, char *sign, long long l, char **number)
{
	print->len_print = 0;
	*sign = '?';
	*sign = (print->plus == 1) ? '+' : *sign;
	*sign = (print->white == 1) ? ' ' : *sign;
	*sign = (l < 0) ? '-' : *sign;
	if (print->precision == -1 && print->zero == 1 && print->width != 1)
		print->precision = (*sign == '?') ? print->width : print->width - 1;
	if (print->precision == 0 && l == 0)
	{
		if (!(*number = ft_strnew(1)))
			return (-1);
		(*number)[0] = (print->plus == 1) ? *sign : (*number)[0];
		return (1);
	}
	else
	{
		if ((*number = itoa_only_digit(l, *sign, print->precision)) == NULL)
		{
			print->printed = NULL;
			return (-1);
		}
	}
	return (1);
}

int		format_di(t_print *print, va_list list_param)
{
	int long long	l;
	char			sign;
	char			*number;
	size_t			len;
	size_t			start_pos;

	set_start(print, list_param, &l);
	if ((set_znak(print, &sign, l, &number)) == -1)
		return (-1);
	len = ft_strlen(number);
	print->len_print = (print->width > 0) ? print->width : 0;
	if (len > print->len_print)
		print->len_print = len;
	if ((print->printed = ft_strnew(print->len_print)) == NULL)
	{
		print->len_print = 0;
		print->printed = NULL;
		return (-1);
	}
	ft_memset(print->printed, ' ', print->len_print);
	start_pos = (print->minus == 1) ? 0 : print->len_print - len;
	ft_strncpy(&(print->printed[start_pos]), number, len);
	ft_strdel(&number);
	return (1);
}
