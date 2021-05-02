/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 10:31:08 by mvuente           #+#    #+#             */
/*   Updated: 2020/05/27 15:33:42 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

t_collect	*flag_parser(const char **format, t_collect *stock)
{
	char *set;
	char c;

	set = "-0";
	while (**format)
	{
		c = **format;
		if (!(ft_strchr(set, c)))
			return (stock);
		if (**format == '-')
			stock->m_flag = 1;
		else
			stock->n_flag = 1;
		*format = *format + 1;
	}
	return (NULL);
}
