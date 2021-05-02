/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 10:31:08 by mvuente           #+#    #+#             */
/*   Updated: 2020/05/27 15:33:42 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	handler(const char **format, t_collect *stock, int charsprint)
{
	if (stock->spec == 'c')
		charsprint = c_handler(stock, charsprint);
	else if (stock->spec == 's')
		charsprint = s_handler(stock, charsprint);
	else if (stock->spec == 'i' || stock->spec == 'd')
		charsprint = di_handler(stock, charsprint);
	else if (stock->spec == 'u')
		charsprint = u_handler(stock, charsprint);
	else if (stock->spec == 'x' || stock->spec == 'X')
		charsprint = hex_handler(stock, charsprint);
	else if (stock->spec == 'p')
		charsprint = p_handler(stock, charsprint);
	else
		charsprint = prcnt_handler(stock, charsprint);
	*format = *format + 1;
	return (charsprint);
}
