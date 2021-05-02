/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 10:31:08 by mvuente           #+#    #+#             */
/*   Updated: 2020/05/27 15:33:42 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	s_handler(t_collect *stock, int charsprinted)
{
	char	*s;
	char	*tmp;

	tmp = va_arg(stock->ap, char*);
	if (tmp == NULL)
	{
		if (!(s = ft_strdup("(null)")))
			return (-1);
	}
	else if (!(s = ft_strdup(tmp)))
		return (-1);
	if (stock->m_flag > 0)
		stock->n_flag = 0;
	if (stock->n_flag == 1)
		stock->space_flag = '0';
	return (string_construct_string(s, stock, charsprinted));
}
