/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgeorge <xgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 15:37:32 by xgeorge           #+#    #+#             */
/*   Updated: 2020/08/07 07:34:54 by xgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/includes/libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef struct		s_print
{
	char			type;
	int				width;
	int				precision;
	void			*poiter;
	char			*printed;
	size_t			len;
	size_t			len_print;
	int				plus;
	int				minus;
	int				white;
	int				sign;
	int				zero;
}					t_print;

/*
**	is fuction a copy fuctuon printf
*/
int					ft_printf(const char *format, ...);
/*
**	read format and void adn insert in dl_print_object
**
**	return 1 if all is okey
**	return -1 if not succeed make new object
*/
int					read_all(char *format, t_dlist **dl_print_object,
								va_list print_param);
/*
**	formating print
*/
int					formating(t_print *print, va_list list_param);
/*
**	print all from dl_print_object
*/
int					print_answer(int *size, t_dlist **dl_print_object);
/*
**	delet dl_print_oject
*/
int					delet_all(t_dlist **dl_print_object);
int					print_delet(t_print **obj);
int					print_set_poiter(t_print *obj, void *poiter);
int					print_set_printed(t_print *obj, char *printed);
/*
**	set type in print
*/
int					print_set_type(t_print *obj, char c);
/*
**	Make new t_print and return him.
**	If mallock not success, then return (NULL).
*/
t_print				*new_t_print(void);
/*
**	Add new list with new print in list.
**	If mallock not success, then return (NULL).
*/
int					make_dlist_with_new_print(t_dlist **list);
/*
** pars printed in t_print and set flags, prescrison and width
*/
int					pars(t_print *print);
/*
**	 if c are flag then return 1 else return -1s
*/
int					is_a_flag(char c);
void				set_stars(t_print *print, va_list list_param);
int					format_s(t_print *print, va_list list_param);
int					format_di(t_print *print, va_list list_param);
int					format_c(t_print *print, va_list list_param);
int					format_proc(t_print *print, va_list list_param);
int					format_u(t_print *print, va_list list_param);
int					format_o(t_print *print, va_list list_param);
int					format_x(t_print *print, va_list list_param);
int					format_p(t_print *print, va_list list_param);
int					format_f(t_print *print, va_list list_param);
/*
**	return poisson width
*/
size_t				get_pw(char *s);
/*
**	 return poisson prescription
*/
size_t				get_pp(char *s);
/*
**	 return poisson size
*/
size_t				get_ps(char *s);
/*
**	 return last poisson flag
*/
size_t				get_lpf(size_t pp, size_t pw, size_t lp);
char				*get_nan_and_inf(long double num, char znak);
size_t				get_next_end_or_param(
		char *format, size_t start);
size_t				get_next_symbol_type(
		char *format, size_t start);
void				set_len_print(t_print *print);
#endif
