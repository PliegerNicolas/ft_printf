/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertor_e.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:02:04 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/21 11:09:30 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_convertor_e(const char *s, t_flags *flags_list, int *i, va_list args)
{
	if (s[*i] == 'e')
	{
		flags_list->str = ft_sntoa(va_arg(args, double), flags_list->precision,
				false);
	}
	else if (s[*i] == 'E')
	{
		flags_list->str = ft_sntoa(va_arg(args, double), flags_list->precision,
				true);
	}
}
