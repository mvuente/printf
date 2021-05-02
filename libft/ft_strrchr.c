/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 10:34:15 by mvuente           #+#    #+#             */
/*   Updated: 2020/05/28 18:20:59 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*res;
	char	smb;
	char	*lastres;

	smb = (char)c;
	res = (char *)s;
	lastres = NULL;
	while (*res)
	{
		if (*res == smb)
			lastres = res;
		res++;
	}
	if (*res == '\0' && smb == '\0')
		return (res);
	else
		return (lastres);
}
