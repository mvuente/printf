/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsign_hextoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 10:35:04 by mvuente           #+#    #+#             */
/*   Updated: 2020/05/28 22:13:41 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		ft_hexlen(long a)
{
	int res;

	res = 0;
	while (a /= 16)
		res++;
	return (res);
}

char	*ft_unsign_hextoa(long a, t_collect *stock)
{
	char			*res;
	unsigned int	tmp;
	int				strlen;

	tmp = (unsigned int)a;
	strlen = 2 + ft_hexlen(tmp);
	if ((res = (char*)malloc(strlen)) == NULL)
		return (NULL);
	res[strlen - 1] = '\0';
	while (--strlen)
	{
		if ((tmp % 16) <= 9)
			res[strlen - 1] = tmp % 16 + 48;
		else if (stock->spec == 'x')
			res[strlen - 1] = tmp % 16 + 87;
		else
			res[strlen - 1] = tmp % 16 + 55;
		tmp = tmp / 16;
	}
	return (res);
}
