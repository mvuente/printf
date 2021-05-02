/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 10:31:08 by mvuente           #+#    #+#             */
/*   Updated: 2020/05/27 15:33:42 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_collect
{
	int			m_flag;
	int			n_flag;
	int			width;
	int			precision;
	char		spec;
	int			sign_flag;
	char		space_flag;
	char		*sign_str;
	int			prec_prcnt_flag;
	va_list		ap;
}				t_collect;

int				ft_printf(const char *format, ...);
int				ft_parser(const char *format, t_collect *stock, int charsprint);
int				basic_printer(const char **format, int charsprinted);
int				prcnt_counter(const char *format);
int				prcnt_printer(const char **format);
int				handler(const char **format, t_collect *stock, int charsprint);
int				c_handler(t_collect *stock, int	charsprinted);
int				s_handler(t_collect *stock, int	charsprinted);
int				di_handler(t_collect *stock, int charsprinted);
int				u_handler(t_collect *stock, int charsprinted);
int				hex_handler(t_collect *stock, int charsprinted);
int				p_handler(t_collect *stock, int charsprinted);
int				prcnt_handler(t_collect *stock, int charsprinted);
t_collect		*flag_parser(const char **format, t_collect *stock);
t_collect		*width_parser(const char **format, t_collect *stock);
t_collect		*precision_parser(const char **format, t_collect *stock);
t_collect		*spec_parser(const char **format, t_collect *stock);
t_collect		*initial(t_collect *stock);
t_collect		*neg_precision(t_collect *stock);
int				my_putstr(char *s, int charsprinted);
char			*ft_unsign_itoa(long a);
char			*ft_unsign_hextoa(long a, t_collect *stock);
char			*ft_long_hextoa(unsigned long a);
int				string_construct(char *s, t_collect *stock, int charsprinted);
int				string_construct_string(char *s, t_collect *stock, int chars);
int				string_construct_char(char s, t_collect *stock, int chars);
int				multiputstr(char *s1, char *s2, char *s3, int charsprinted);

#endif
