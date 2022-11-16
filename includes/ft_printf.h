/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 10:00:33 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/16 17:58:22 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

# define TYPE_IDENTIFIERS "dioxXucsfeEgGpn"
# define FLAG_IDENTIFIERS "-0+ #*"

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
	float	padding;
	t_bool	dot;
	t_bool	hash;
}	t_flags;

int		ft_printf(const char *format, ...);

t_flags	*ft_initialize_flags(void);
void	ft_next_flags(t_flags *flags);

int		ft_isflag(const char c);
int		ft_istype(const char c);

int		ft_handler_percent(const char *s, t_flags *flags_list, int *i);
void	ft_handler_flags_setter(const char *s, va_list args,
			t_flags *flags_list, int *i);
void	ft_handler_flags(const char *s, va_list args, t_flags *flags_list,
			int *i);
void	ft_handler_args(const char *s, va_list args, t_flags *flags_list,
			int *i);

int		ft_parse_format(const char *s, va_list args, t_flags *flags_list);
int		ft_putcharc(const char c, t_flags *flags_list);
void	ft_putstrc(const char *s, t_flags *flags_list, int *i);
void	ft_putpadding(const char c, t_flags *flags_list);
char	*ft_strrev(char *str);
char	*ft_itoa_base(int nb, const char *base);
char	*ft_ltoa_base(unsigned long nb, const char *base);

void	ft_dash_setter(const char *s, t_flags *flags_list, int *i);
void	ft_dash_convertor(const char *s, t_flags *flags_list, int *i);
void	ft_zero_setter(const char *s, t_flags *flags_list, int *i);
void	ft_zero_convertor(const char *s, t_flags *flags_list, int *i);
void	ft_asterisk_setter(const char *s, va_list args, t_flags *flags_lisit,
			int *i);
void	ft_asterisk_convertor(const char *s, va_list args, t_flags *flags_list,
			int *i);
void	ft_digits_setter(const char *s, t_flags *flags_list, int *i);
void	ft_digits_convertor(const char *s, t_flags *flags_list, int *i);
void	ft_plus_setter(const char *s, t_flags *flags_list, int *i);
void	ft_plus_convertor(const char *s, t_flags *flags_list, int *i);
void	ft_blank_setter(const char *s, t_flags *flags_list, int *i);
void	ft_blank_convertor(const char *s, t_flags *flags_list, int *i);
void	ft_hash_setter(const char *s, t_flags *flags_list, int *i);
void	ft_hash_convertor(const char *s, t_flags *flags_list, int *i);

void	ft_convertor_d(const char *s, t_flags *flags_list, int *i,
			va_list args);
void	ft_convertor_i(const char *s, t_flags *flags_list, int *i,
			va_list args);
void	ft_convertor_o(const char *s, t_flags *flags_list, int *i,
			va_list args);
void	ft_convertor_x(const char *s, t_flags *flags_list, int *i,
			va_list args);
void	ft_convertor_X(const char *s, t_flags *flags_list, int *i,
			va_list args);
void	ft_convertor_u(const char *s, t_flags *flags_list, int *i,
			va_list args);
void	ft_convertor_c(const char *s, t_flags *flags_list, int *i,
			va_list args);
void	ft_convertor_s(const char *s, t_flags *flags_list, int *i,
			va_list args);
void	ft_convertor_f(const char *s, t_flags *flags_list, int *i,
			va_list args);

#endif
