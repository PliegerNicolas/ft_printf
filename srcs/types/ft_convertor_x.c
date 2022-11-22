/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertor_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:53:43 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/22 15:14:55 by nplieger         ###   ########.fr       */
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
	}
	else if (s[*i] == 'X')
	{
		flags_list->str = ft_ltoa_base(va_arg(args, unsigned int),
				"0123456789ABCDEF");
		flags_list->type = 'X';
	}
}
