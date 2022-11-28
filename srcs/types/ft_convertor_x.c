/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertor_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:53:43 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/28 09:17:35 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

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
