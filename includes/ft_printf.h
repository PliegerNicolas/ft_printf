/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 10:00:33 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/14 17:10:41 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

# define TYPE_IDENTIFIERS "dioxXucsfeEgGpn"
# define FLAG_IDENTIFIERS "-0+ #"

typedef int	t_bool;
enum { false, true };

typedef struct s_flags
{
	char	*str;
	int		tw_chars;
	t_bool	percent;

	t_bool	dash;
	t_bool	zero;
	t_bool	plus;
	t_bool	blank;
	t_bool	asterisk;
	int		padding;
	t_bool	dot;
	float	precision_value;
	char	precision_type;

	t_bool	hash;
	t_bool	octal;
	t_bool	hex;
	t_bool	decimal_point;
	t_bool	decimal_point_zeros;
}	t_flags;

int		ft_printf(const char *format, ...);

t_flags	*ft_initialize_flags(void);
void	ft_next_flags(t_flags *flags);

int		ft_isflag(const char c);
int		ft_istype(const char c);

int		ft_handler_percent(const char *s, t_flags *flags_list, int *i);
void	ft_handler_flags(const char *s, t_flags *flags_list, int *i);
void	ft_handler_args(const char *s, va_list args, t_flags *flags_list,
			int *i);

int		ft_parse_format(const char *s, va_list args, t_flags *flags_list);
int		ft_putcharc(const char c, t_flags *flags_list);
void	ft_putstrc(const char *s, t_flags *flags_list, int *i);
void	ft_put_padding(const char c, t_flags *flags_list);

void	ft_convertor_d(int arg, t_flags *flags_list);
void	ft_convertor_i(int arg, t_flags *flags_list);

#endif
