/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:23:49 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/15 12:56:20 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	ft_padding(t_flags *flags_list)
{
	if (flags_list->padding)
	{
		if (flags_list->zero)
			ft_putpadding('0', flags_list);
		else
			ft_putpadding(' ', flags_list);
	}
}

void	ft_printer(t_flags *flags_list, int *i)
{
	flags_list->padding -= ft_strlen(flags_list->str);
	if (!flags_list->dash)
		ft_padding(flags_list);
	ft_putstrc(flags_list->str, flags_list, i);
	ft_padding(flags_list);
	ft_next_flags(flags_list);
}

int	ft_parse_format(const char *s, va_list args, t_flags *flags_list)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (ft_handler_percent(s, flags_list, &i))
		{
			ft_handler_flags(s, args, flags_list, &i);
			ft_handler_args(s, args, flags_list, &i);
			if (flags_list->str)
				ft_printer(flags_list, &i);
		}
		else
			ft_putcharc(s[i++], flags_list);
	}
	return (flags_list->tw_chars);
}
