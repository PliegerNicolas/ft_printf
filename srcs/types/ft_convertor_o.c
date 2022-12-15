/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertor_o.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:47:21 by nplieger          #+#    #+#             */
/*   Updated: 2022/12/15 13:53:40 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_convertor_o(const char *s, t_flags *flags, int *i, va_list args)
{
	char	*str;

	if (s[*i] == 'o')
	{
		str = ft_ltoa_base(va_arg(args, unsigned int), "01234567");
		if (!str)
			return ;
		flags->str = str;
		flags->strlen = ft_strlen(flags->str);
		flags->type = 'o';
		if (!flags->dot)
			flags->precision = 1;
	}
}
