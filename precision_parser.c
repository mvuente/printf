/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 10:31:08 by mvuente           #+#    #+#             */
/*   Updated: 2020/05/27 15:33:42 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

t_collect	*conditions_parser(const char **format, t_collect *stock)
{
	if (ft_strchr("cspdiuxX", **format))
		stock->precision = 0;
	else
	{
		stock->precision = va_arg(stock->ap, int);
		*format = *format + 1;
	}
	return (stock);
}

int			local_atoi(const char **format, int flag)
{
	char	c;
	int		temp;

	temp = 0;
	while (**format && ft_isdigit(**format))
	{
		c = **format;
		temp = temp * 10 + (c - 48);
		*format = *format + 1;
	}
	return (temp * flag);
}

t_collect	*precision_parser(const char **format, t_collect *stock)
{
	int		flag;

	flag = 1;
	if (!(**format))
		return (NULL);
	if (**format != '.')
		return (stock);
	*format = *format + 1;
	if (!(ft_isdigit(**format)) && **format != '*' &&
		!(ft_strchr("-cspdiuxX%", **format)))
		return (NULL);
	if (ft_strchr("*cspdiuxX%", **format))
		return (conditions_parser(format, stock));
	else if (**format == '-')
	{
		stock->prec_prcnt_flag = 1;
		*format = *format + 1;
		flag = -1;
	}
	if (ft_isdigit(**format))
		stock->precision = local_atoi(format, flag);
	else
		return (NULL);
	return (stock);
}
