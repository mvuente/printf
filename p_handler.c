/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 10:31:08 by mvuente           #+#    #+#             */
/*   Updated: 2020/05/27 15:33:42 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	p_handler(t_collect *stock, int charsprinted)
{
	unsigned long	num;
	char			*s;

	num = va_arg(stock->ap, unsigned long);
	if (num == 0 && stock->precision == 0)
	{
		if (!(s = (char*)malloc(3)))
			return (-1);
		ft_strlcpy(s, "0x", 3);
	}
	else if (!(s = ft_long_hextoa(num)))
		return (-1);
	if (stock->precision > -1 || stock->m_flag > 0)
		stock->n_flag = 0;
	if (stock->n_flag == 1)
		stock->space_flag = '0';
	return (string_construct(s, stock, charsprinted));
}
