/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 10:31:08 by mvuente           #+#    #+#             */
/*   Updated: 2020/05/27 15:33:42 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

t_collect	*is_negative(t_collect *stock)
{
	if (stock->width < 0)
	{
		stock->width = -stock->width;
		stock->m_flag = 1;
	}
	return (stock);
}

t_collect	*width_parser(const char **format, t_collect *stock)
{
	char c;

	if (!(**format))
		return (NULL);
	if (!(ft_isdigit(**format)) && **format != '*')
		return (stock);
	if (**format == '*')
	{
		stock->width = va_arg(stock->ap, int);
		*format = *format + 1;
	}
	else
	{
		while (**format && ft_isdigit(**format))
		{
			c = **format;
			stock->width = stock->width * 10 + (c - 48);
			*format = *format + 1;
		}
	}
	stock = is_negative(stock);
	return (stock);
}
