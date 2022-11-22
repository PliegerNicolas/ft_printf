/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertor_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:26:21 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/22 15:14:26 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_convertor_u(const char *s, t_flags *flags_list, int *i, va_list args)
{
	if (s[*i] == 'u')
	{
		flags_list->str = ft_ltoa_base(va_arg(args, unsigned int),
				"0123456789");
		flags_list->type = 'u';
	}
}
