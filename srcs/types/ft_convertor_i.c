/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertor_i.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:22:38 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/28 09:13:55 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_convertor_i(const char *s, t_flags *flags_list, int *i, va_list args)
{
	if (s[*i] == 'i')
	{
		flags_list->str = ft_itoa(va_arg(args, int));
		flags_list->type = 'i';
		ft_int_flagger(flags_list, ft_strlen(flags_list->str));
	}
}
