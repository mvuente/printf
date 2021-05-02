/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 10:31:08 by mvuente           #+#    #+#             */
/*   Updated: 2020/05/27 15:33:42 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

t_collect	*initial(t_collect *stock)
{
	stock->m_flag = 0;
	stock->n_flag = 0;
	stock->width = 0;
	stock->precision = -1;
	stock->spec = '0';
	stock->space_flag = ' ';
	stock->sign_flag = 0;
	stock->sign_str = NULL;
	stock->prec_prcnt_flag = 0;
	return (stock);
}
