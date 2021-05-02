/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_hextoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 10:31:08 by mvuente           #+#    #+#             */
/*   Updated: 2020/05/27 15:33:42 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		ft_p_len(unsigned long a)
{
	int res;

	res = 0;
	while (a /= 16)
		res++;
	return (res);
}

char	*ft_long_hextoa(unsigned long a)
{
	char			*res;
	int				strlen;

	strlen = 4 + ft_p_len(a);
	if (!(res = (char*)malloc(strlen)))
		return (NULL);
	res[strlen - 1] = '\0';
	res[0] = '0';
	res[1] = 'x';
	while (--strlen > 2)
	{
		if ((a % 16) <= 9)
			res[strlen - 1] = a % 16 + 48;
		else
			res[strlen - 1] = a % 16 + 87;
		a = a / 16;
	}
	return (res);
}
