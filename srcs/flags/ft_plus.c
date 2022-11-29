/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:16:19 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/29 10:41:53 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_plus_setter(const char *s, t_flags *flags_list, int *i)
{
	if (s[*i] == '+')
	{
		flags_list->plus = TRUE;
		(*i)++;
	}
}

void	ft_plus_convertor(t_flags *flags)
{
	(void)flags;
}
