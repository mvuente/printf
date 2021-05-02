/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiputstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 10:31:08 by mvuente           #+#    #+#             */
/*   Updated: 2020/05/27 15:33:42 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	multiputstr(char *s1, char *s2, char *s3, int charsprinted)
{
	charsprinted = my_putstr(s1, charsprinted);
	charsprinted = my_putstr(s2, charsprinted);
	charsprinted = my_putstr(s3, charsprinted);
	return (charsprinted);
}
