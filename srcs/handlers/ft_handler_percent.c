/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_percent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:04:10 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/14 12:39:37 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_handler_percent(const char *s, t_flags *flags_list, int *i)
{
	if (s[*i] == '%' && !flags_list->percent)
	{
		(*i)++;
		flags_list->percent = true;
		return (1);
	}
	else if (s[*i] == '%' && flags_list->percent)
		ft_next_flags(flags_list);
	return (0);
}
