/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asterisk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 09:59:10 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/16 13:37:27 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_asterisk_setter(const char *s, va_list args, t_flags *flags_list,
			int *i)
{
	if (s[*i] == '*')
	{
		flags_list->asterisk = true;
		flags_list->padding = va_arg(args, int);
		(*i)++;
	}
}

void	ft_asterisk_convertor(const char *s, va_list args, t_flags *flags_list,
			int *i)
{
	if (s[*i] == '*')
	{
		flags_list->asterisk = true;
		flags_list->padding = va_arg(args, int);
		(*i)++;
	}
}
