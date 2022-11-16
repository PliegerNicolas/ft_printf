/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 09:56:54 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/16 13:50:07 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_zero_setter(const char *s, t_flags *flags_list, int *i)
{
	if (s[*i] == '0')
	{
		flags_list->zero = true;
		(*i)++;
	}
}

void	ft_zero_convertor(const char *s, t_flags *flags_list, int *i)
{
	if (s[*i] == '0')
	{
		flags_list->zero = true;
		(*i)++;
	}
}
