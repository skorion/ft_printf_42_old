/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgeorge <xgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 23:51:41 by xgeorge           #+#    #+#             */
/*   Updated: 2020/06/24 23:52:25 by xgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_a_flag(char c)
{
	if (c == '+' ||
		c == '-' ||
		c == ' ' ||
		c == '#' ||
		c == '0')
		return (1);
	return (-1);
}
