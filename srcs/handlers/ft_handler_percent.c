/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_percent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:04:10 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/29 10:49:27 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_handler_percent(const char *s, t_flags *flags, int *i)
{
	if (s[*i] == '%' && !flags->percent)
	{
		(*i)++;
		flags->percent = TRUE;
		return (1);
	}
	else if (s[*i] == '%' && flags->percent)
		ft_next_flags(flags);
	return (0);
}
