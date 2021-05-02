/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 10:31:08 by mvuente           #+#    #+#             */
/*   Updated: 2020/05/27 15:33:42 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		di_handler(t_collect *stock, int charsprinted)
{
	char	*s;
	int		num;

	if ((num = va_arg(stock->ap, int)) < 0)
	{
		stock->sign_flag = 1;
		if (!(stock->sign_str = ft_strdup("-")))
			return (-1);
	}
	if (!(s = ft_itoa(num)))
		return (-1);
	if (stock->precision > -1 || stock->m_flag > 0)
		stock->n_flag = 0;
	if (stock->n_flag == 1)
		stock->space_flag = '0';
	return (string_construct(s, stock, charsprinted));
}
