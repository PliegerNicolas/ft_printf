/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertor_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:26:21 by nplieger          #+#    #+#             */
/*   Updated: 2022/12/15 13:53:22 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_convertor_u(const char *s, t_flags *flags, int *i, va_list args)
{
	char	*str;

	if (s[*i] == 'u')
	{
		str = ft_ltoa_base(va_arg(args, unsigned int), "0123456789");
		if (!str)
			return ;
		flags->str = str;
		flags->type = 'u';
		if (flags->dot)
			flags->zero = FALSE;
		ft_numeric_clear_zero(flags);
		flags->strlen = ft_strlen(flags->str);
		ft_numeric_paddnegative(flags, flags->strlen, FALSE);
		if (flags->max_width < flags->strlen)
			flags->max_width = flags->strlen;
		flags->precision = flags->max_width;
	}
}
