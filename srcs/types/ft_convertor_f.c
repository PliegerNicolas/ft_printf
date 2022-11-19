/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertor_f.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:56:25 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/18 17:19:26 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_convertor_f(const char *s, t_flags *flags_list, int *i, va_list args)
{
	if (s[*i] == 'f')
		flags_list->str = ft_dtoa(va_arg(args, double), flags_list->precision);
}