/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft__unsign_itoa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 10:35:04 by mvuente           #+#    #+#             */
/*   Updated: 2020/05/28 22:13:41 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		ft_intlen_u(long a)
{
	int res;

	res = 0;
	while (a /= 10)
		res++;
	return (res);
}

char	*ft_unsign_itoa(long a)
{
	char			*res;
	unsigned int	tmp;
	int				strlen;

	tmp = (unsigned int)a;
	strlen = 2 + ft_intlen_u(tmp);
	if ((res = (char*)malloc(strlen)) == NULL)
		return (NULL);
	res[strlen - 1] = '\0';
	while (--strlen)
	{
		res[strlen - 1] = tmp % 10 + 48;
		tmp = tmp / 10;
	}
	return (res);
}
