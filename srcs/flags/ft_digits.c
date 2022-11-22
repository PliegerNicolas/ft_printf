/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:08:41 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/22 17:19:16 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_digits_setter(const char *s, t_flags *flags_list, int *i)
{
	if (!flags_list->asterisk)
	{
		flags_list->padding = 0;
		while (ft_isdigit(s[*i]) || s[*i] == '.')
		{
			if (s[*i] == '.')
			{
				(*i)++;
				continue ;
			}
			else
			{
				flags_list->padding *= 10;
				flags_list->padding += s[(*i)++] - '0';
			}
		}
		if (s[*i - 1] == '.')
		{
			while (ft_isdigit(s[(*i)]))
			{
				flags_list->dot *= 10;
				flags_list->dot += s[*i++] - '0';
			}
		}
	}
}

void	ft_digits_convertor(t_flags *flags_list)
{
	size_t		strlen;

	if (!flags_list->asterisk && (int)flags_list->padding != 0)
	{
		if (flags_list->dot)
			strlen = flags_list->dot;
		else
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
	}
	flags_list->padding = 0;
}
