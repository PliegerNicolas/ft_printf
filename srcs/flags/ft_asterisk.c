/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asterisk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 09:59:10 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/22 16:40:57 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_asterisk_setter(const char *s, va_list args, t_flags *flags_list,
			int *i)
{
	if (s[*i] == '*' && flags_list->type)
	{
		flags_list->asterisk = TRUE;
		flags_list->padding = va_arg(args, int);
		(*i)++;
	}
}

void	ft_asterisk_convertor(t_flags *flags_list)
{
	size_t		strlen;

	if (flags_list->asterisk)
	{
		strlen = ft_strlen(flags_list->str);
		if (flags_list->type == '\0')
			strlen++;
		if (flags_list->dash)
			flags_list->str = ft_realloc_str(flags_list->str,
					strlen, flags_list->padding);
		else
			flags_list->str = ft_realloc_paddedstr(flags_list->str,
					strlen, flags_list->padding);
		if (flags_list->padding > strlen)
			ft_fillpadding(flags_list->str, strlen, flags_list);
		flags_list->asterisk = FALSE;
		flags_list->padding = 0;
	}
}
