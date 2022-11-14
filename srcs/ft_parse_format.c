/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:23:49 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/14 13:40:05 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_parse_format(const char *s, va_list args, t_flags *flags_list)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (ft_handler_percent(s, flags_list, &i))
		{
			ft_handler_flags(s, flags_list, &i);
			ft_handler_args(s, args, flags_list, &i);
		}
		else
			ft_putcharc(s[i++], flags_list);
	}
	return (flags_list->tw_chars);
}
