/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_construct_char.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 10:31:08 by mvuente           #+#    #+#             */
/*   Updated: 2020/05/27 15:33:42 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void		widthwrite(char symb, int additive)
{
	while (additive--)
	{
		write(1, &symb, 1);
	}
}

int			cond_width_c(char s, t_collect *stock, int charspr)
{
	int		additive;

	if (stock->width > 1)
	{
		additive = stock->width - 1;
		if (stock->m_flag == 1)
		{
			write(1, &s, 1);
			widthwrite(32, additive);
		}
		else
		{
			if (stock->n_flag == 0)
				widthwrite(32, additive);
			else
				widthwrite(48, additive);
			write(1, &s, 1);
		}
		return (charspr += stock->width);
	}
	return (0);
}

int			string_construct_char(char s, t_collect *stock, int charsprinted)
{
	int	temp;

	stock = neg_precision(stock);
	if ((temp = cond_width_c(s, stock, charsprinted)))
		return (temp);
	write(1, &s, 1);
	charsprinted += 1;
	return (charsprinted);
}
