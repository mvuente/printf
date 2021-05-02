/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_construct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 10:31:08 by mvuente           #+#    #+#             */
/*   Updated: 2020/05/27 15:33:42 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

t_collect	*m_flag_neg_arg(t_collect *stock)
{
	stock->sign_flag = 0;
	free(stock->sign_str);
	stock->sign_str = NULL;
	return (stock);
}

char		*cond_prec(char *s, t_collect *stock)
{
	char	*number;
	int		additive;
	char	*tmp;

	if (stock->precision > (int)ft_strlen(s))
	{
		additive = stock->precision - (int)ft_strlen(s) + stock->sign_flag;
		if (!(number = (char*)malloc(additive + 1)))
			return (NULL);
		number[additive] = '\0';
		number = ft_memset(number, 48, additive);
		if (stock->sign_flag == 1)
			number[0] = '-';
		tmp = ft_strjoin(number, s);
		free(number);
		if (!tmp)
			return (NULL);
		free(s);
		s = tmp;
	}
	return (s);
}

int			costyl(char *add, int additive, t_collect *stock, int charspr)
{
	add = ft_memset(add, 48, additive);
	return (multiputstr(stock->sign_str, add, NULL, charspr));
}

int			cond_width(char *s, t_collect *stock, int charspr)
{
	int		additive;
	char	*add;

	if (stock->width > stock->sign_flag + (int)ft_strlen(s))
	{
		additive = stock->width - (int)ft_strlen(s) - stock->sign_flag;
		if (!(add = (char*)ft_calloc(additive + 1, 1)))
			return (-1);
		add = ft_memset(add, 32, additive);
		if (stock->m_flag == 1)
			charspr = multiputstr(stock->sign_str, s, add, charspr);
		else
		{
			if (stock->n_flag == 0)
				charspr = multiputstr(add, stock->sign_str, NULL, charspr);
			else
				charspr = costyl(add, additive, stock, charspr);
			charspr = my_putstr(s, charspr);
		}
		free(add);
		return (charspr);
	}
	return (0);
}

int			string_construct(char *s, t_collect *stock, int charsprinted)
{
	int	temp;

	stock = neg_precision(stock);
	if (stock->precision == 0 && *s == '0' && stock->spec != 'p')
		*s = '\0';
	if (stock->precision > (int)ft_strlen(s) || stock->width > stock->sign_flag
		+ (int)ft_strlen(s))
	{
		if (!(s = cond_prec(s, stock)))
			return (-1);
		if (stock->sign_flag == 1 && *s == '-')
			stock = m_flag_neg_arg(stock);
		if ((temp = cond_width(s, stock, charsprinted)))
		{
			free(s);
			return (temp);
		}
	}
	charsprinted = my_putstr(stock->sign_str, charsprinted);
	charsprinted = my_putstr(s, charsprinted);
	free(s);
	return (charsprinted);
}
