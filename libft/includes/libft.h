/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgeorge <xgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:37:32 by xgeorge           #+#    #+#             */
/*   Updated: 2020/08/07 01:46:45 by xgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <math.h>

typedef struct				s_list
{
	void					*content;
	size_t					content_size;
	struct s_list			*next;
}							t_list;
void						*ft_memset(void *b, int c, size_t len);
void						ft_bzero(void *s, size_t n);
void						*ft_memcpy(void *dst,
											const void *src, size_t n);
void						*ft_memccpy(void *dst, const void
												*src, int c, size_t n);
void						*ft_memmove(void *dst, const void *src, size_t len);
void						*ft_memchr(const void *s, int c, size_t n);
int							ft_memcmp(const void *s1, const void *s2, size_t n);
size_t						ft_strlen(const char *s);
char						*ft_strdup(const char *s1);
char						*ft_strcpy(char *dst, const char *src);
char						*ft_strncpy(char *dst,
											const char *src, size_t len);
char						*ft_strcat(char *s1,
												const char *s2);
char						*ft_strncat(char *s1,
										const char *s2, size_t n);
size_t						ft_strlcat(char *s1,
									const char *s2, size_t size);
char						*ft_strchr(const char *s, int c);
char						*ft_strrchr(const char *s, int c);
char						*ft_strstr(const char *haystack,
														const char *needle);
char						*ft_strnstr(const char *haystack,
											const char *needle, size_t len);
int							ft_strcmp(const char *s1, const char *s2);
int							ft_strncmp(const char *s1, const char *s2,
														size_t n);
int							ft_atoi(const char *str);
int							ft_isalpha(int c);
int							ft_isdigit(int c);
int							ft_isalnum(int c);
int							ft_isascii(int c);
int							ft_isprint(int c);
int							ft_toupper(int c);
int							ft_tolower(int c);
void						*ft_memalloc(size_t size);
void						ft_memdel(void **ap);
char						*ft_strnew(size_t size);
void						ft_strdel(char **as);
void						ft_strclr(char *s);
void						ft_striter(char *s, void (*f)(char *));
void						ft_striteri(char *s, void (*f)(unsigned int,
																char *));
char						*ft_strmap(char const *s, char (*f)(char));
char						*ft_strmapi(char const *s,
											char(*f)(unsigned int, char));
int							ft_strequ(char const *s1, char const *s2);
int							ft_strnequ(char const *s1,
													char const *s2, size_t n);
char						*ft_strsub(char const *s,
												unsigned int start, size_t len);
char						*ft_strjoin(char const *s1, char const *s2);
char						*ft_strtrim(char const *s);
char						**ft_strsplit(char const *s, char c);
char						*ft_itoa(int n);
void						ft_putchar(char c);
void						ft_putstr(char const *s);
void						ft_putendl(char const *s);
void						ft_putnbr(int n);
void						ft_putchar_fd(char c, int fd);
void						ft_putstr_fd(char const *s, int fd);
void						ft_putendl_fd(char const *s, int fd);
void						ft_putnbr_fd(int n, int fd);
t_list						*ft_lstnew(void const *content,
														size_t content_size);
void						ft_lstdelone(t_list **alst,
										void (*del)(void *, size_t));
void						ft_lstdel(t_list **alst,
									void (*del)(void *, size_t));
void						ft_lstadd(t_list **alst, t_list *new);
void						ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list						*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
size_t						ft_numlen(int n);
int							ft_invisible(int c);
size_t						ft_max_t_size(size_t a, size_t b);
char						**ft_clean_tab(char **tab);
int							ft_sqrt(int nb);
int							*ft_range(int min, int max);
int long long				ft_reduse(int long long delimoe,
														int long long delitel);

int							ft_is_a_inf_or_nan(long double num);
char						*ft_gcvt(long double value, int precision);
unsigned long long int		ft_ullpower(unsigned long long num, int power);
size_t						ft_ullnumlen(unsigned long long n);
size_t						ft_llinumlen(long long int n);
char						*ft_strcat_loop(char *dest,
													int x_times, char *source);
typedef struct				s_dlist
{
	void					*content;
	size_t					content_size;
	struct s_dlist			*next;
	struct s_dlist			*prev;
}							t_dlist;
/*
**	need check: NULL
*/
t_dlist						*ft_newdlist(void *content, size_t content_size);
/*
**	need free: item->prew
*/
t_dlist						*ft_addenddlist(t_dlist **box, t_dlist *item);
/*
**	need free: *box->next
**	return: *item
*/
t_dlist						*ft_insertdlist(t_dlist **box, t_dlist *item);
/*
**	need free: *box->prew
*/
t_dlist						*ft_addstartdlist(t_dlist **box, t_dlist *item);
/*
**	kill *box
**	and return *box->next if *box exist
**	else returm *box->prev
*/
t_dlist						*ft_removedlist(t_dlist **box,
												void (*del)(void*, size_t));
/*
**	kill all dlist
*/
void						ft_cleardlist(t_dlist **box,
												void (*del)(void*, size_t));
#endif
