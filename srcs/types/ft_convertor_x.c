/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertor_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:53:43 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/29 13:42:45 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

/*
void	ft_convertor_x(const char *s, t_flags *flags_list, int *i, va_list args)
{
	if (s[*i] == 'x')
	{
		flags_list->str = ft_ltoa_base(va_arg(args, unsigned int),
				"0123456789abcdef");
		flags_list->type = 'x';
		ft_int_flagger(flags_list, ft_strlen(flags_list->str));
	}
	else if (s[*i] == 'X')
	{
		flags_list->str = ft_ltoa_base(va_arg(args, unsigned int),
				"0123456789ABCDEF");
		flags_list->type = 'X';
		ft_int_flagger(flags_list, ft_strlen(flags_list->str));
	}
}
*/

void	ft_convertor_x(const char *s, t_flags *flags, int *i, va_list args)
{
	char	*str;

	if (s[*i] == 'x' || s[*i] == 'X')
	{
		if (s[*i] == 'x')
		{
			str = ft_ltoa_base(va_arg(args, unsigned int), "0123456789abcdef");
			flags->type = 'x';
		}
		if (s[*i] == 'X')
		{
			str = ft_ltoa_base(va_arg(args, unsigned int), "0123456789ABCDEF");
			flags->type = 'X';
		}
		if (!str)
		{
			flags->type = '\0';
			return ;
		}
		flags->str = str;
		flags->strlen = ft_strlen(flags->str);
		if (!flags->dot)
			flags->precision = 1;
		if (flags->max_width < flags->strlen)
			flags->max_width = flags->strlen;
	}
}
