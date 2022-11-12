/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 10:00:33 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/12 18:01:28 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

# define FORMAT_IDENTIFIERS "dioxXucsfeEgGpn"
# define FLAGS "-0+ #"

typedef int	t_bool;
enum { false, true };

typedef struct s_flags
{
	char	type;
	int		total_written_chars;
	t_bool	percent;

	t_bool	dash;	// Left justify with ' ' (defaut right)
	t_bool	zero;	// justify with '0'
	t_bool	plus;	// Display sign
	t_bool	blank;	// ' ' infront of + value.
	t_bool	asterisk;
	int		padding_size;
	t_bool	dot;	// precision
	float	precision_value;
	char	precision_type;	// s or f for float or string.

	t_bool	hash;
	t_bool	octal;
	t_bool	hex;
	t_bool	caps_hex;
	t_bool	decimal_point;
	t_bool	decimal_point_zeros;
}	t_flags;

int		ft_printf(const char *format, ...);
t_flags	*ft_initialize_flags(void);
void	ft_next_flags(t_flags *flags);

#endif
