/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertor_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:26:21 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/29 13:42:03 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

/*
void	ft_convertor_u(const char *s, t_flags *flags_list, int *i, va_list args)
{
	if (s[*i] == 'u')
	{
		flags_list->str = ft_ltoa_base(va_arg(args, unsigned int),
				"0123456789");
		flags_list->type = 'u';
		ft_int_flagger(flags_list, ft_strlen(flags_list->str));
	}
}
*/

void	ft_convertor_u(const char *s, t_flags *flags, int *i, va_list args)
{
	char	*str;

	if (s[*i] == 'u')
	{
		str = ft_ltoa_base(va_arg(args, unsigned int), "0123456789");
		if (!str)
			return ;
		flags->str = str;
		flags->strlen = ft_strlen(flags->str);
		flags->type = 'u';
		if (!flags->dot)
			flags->precision = 1;
		if (flags->max_width < flags->strlen)
			flags->max_width = flags->strlen;
	}
}
