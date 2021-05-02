/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_construct_string.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 10:31:08 by mvuente           #+#    #+#             */
/*   Updated: 2020/05/27 15:33:42 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int			multiputstr_s(char *s1, char *s2, char *s3, int charsprinted)
{
	charsprinted = my_putstr(s1, charsprinted);
	charsprinted = my_putstr(s2, charsprinted);
	charsprinted = my_putstr(s3, charsprinted);
	return (charsprinted);
}

int			cond_width_s(char *s, t_collect *stock, int charspr)
{
	int		additive;
	char	*add;

	if (stock->width > stock->sign_flag + (int)ft_strlen(s))
	{
		additive = stock->width - (int)ft_strlen(s) - stock->sign_flag;
		if (!(add = (char*)ft_calloc(' ', additive + 1)))
			return (-1);
		add = ft_memset(add, 32, additive);
		if (stock->m_flag == 1)
			charspr = multiputstr(stock->sign_str, s, add, charspr);
		else
		{
			if (stock->n_flag == 0)
				charspr = multiputstr(add, stock->sign_str, NULL, charspr);
			else
			{
				add = ft_memset(add, 48, additive);
				charspr = multiputstr(stock->sign_str, add, NULL, charspr);
			}
			charspr = my_putstr(s, charspr);
		}
		return (charspr);
	}
	return (0);
}

int			string_construct_string(char *s, t_collect *stock, int charsprinted)
{
	int	temp;

	stock = neg_precision(stock);
	if (stock->precision == 0 && stock->spec == 's')
		ft_bzero(s, ft_strlen(s));
	if (stock->precision < (int)ft_strlen(s) && stock->spec == 's')
		s[stock->precision] = '\0';
	if ((temp = cond_width_s(s, stock, charsprinted)))
	{
		free(s);
		return (temp);
	}
	charsprinted = my_putstr(s, charsprinted);
	free(s);
	return (charsprinted);
}
