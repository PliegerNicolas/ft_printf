/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertor_o.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:47:21 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/15 15:38:03 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_convertor_o(const char *s, t_flags *flags_list, int *i, va_list args)
{
	if (s[*i] == 'o')
		flags_list->str = ft_ltoa_base(va_arg(args, unsigned int), "01234567");
}
