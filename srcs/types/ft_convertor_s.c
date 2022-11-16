/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertor_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:47:45 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/16 17:48:10 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_convertor_s(const char *s, t_flags *flags_list, int *i, va_list args)
{
	if (s[*i] == 's')
		flags_list->str = ft_strdup(va_arg(args, char *));
}

