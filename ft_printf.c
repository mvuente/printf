/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 10:31:08 by mvuente           #+#    #+#             */
/*   Updated: 2020/05/27 15:33:42 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_printf(const char *format, ...)
{
	int			charsprinted;
	t_collect	*stock;

	if (!format)
		return (-1);
	charsprinted = 0;
	if (!(stock = (t_collect*)malloc(sizeof(t_collect))))
		return (-1);
	stock = initial(stock);
	va_start(stock->ap, format);
	charsprinted = ft_parser(format, stock, charsprinted);
	va_end(stock->ap);
	if (stock->sign_str)
		free(stock->sign_str);
	free(stock);
	return (charsprinted);
}
