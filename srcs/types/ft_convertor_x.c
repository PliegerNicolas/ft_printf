/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertor_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:53:43 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/30 14:51:31 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_convertor_x(const char *s, t_flags *flags, int *i, va_list args)
{
	char	*str;

	if (s[*i] == 'x' || s[*i] == 'X')
	{
		if (s[*i] == 'x')
			str = ft_ltoa_base(va_arg(args, unsigned int), "0123456789abcdef");
		else
			str = ft_ltoa_base(va_arg(args, unsigned int), "0123456789ABCDEF");
		if (!str)
			return ;
		if (s[*i] == 'x')
			flags->type = 'x';
		else
			flags->type = 'X';
		flags->str = str;
		flags->strlen = ft_strlen(flags->str);
		if (ft_numeric_digits(flags))
			return ;
		if (ft_numeric_precision(flags))
			return ;
	}
}
