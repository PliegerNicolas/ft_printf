/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertor_d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:22:11 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/25 15:22:04 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_convertor_d(const char *s, t_flags *flags_list, int *i, va_list args)
{
	size_t		strlen;

	if (s[*i] == 'd')
	{
		flags_list->str = ft_itoa(va_arg(args, int));
		flags_list->type = 'd';
		strlen = ft_strlen(flags_list->str);
		ft_realloc_int(flags_list, strlen);
	}
}
