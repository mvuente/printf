/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 10:31:08 by mvuente           #+#    #+#             */
/*   Updated: 2020/05/27 15:33:42 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_parser(const char *format, t_collect *stock, int charsprint)
{
	while (*format)
	{
		if (*format != '%')
			charsprint = basic_printer(&format, charsprint);
		else if (!(prcnt_counter(format) % 2))
			charsprint += prcnt_printer(&format);
		else
		{
			charsprint += prcnt_printer(&format);
			stock = initial(stock);
			if (!(stock = flag_parser(&format, stock)))
				return (-1);
			if (!(stock = width_parser(&format, stock)))
				return (-1);
			if (!(stock = precision_parser(&format, stock)))
				return (-1);
			if (!(stock = spec_parser(&format, stock)))
				return (-1);
			if ((charsprint = handler(&format, stock, charsprint)) < 0)
				return (-1);
		}
	}
	return (charsprint);
}
