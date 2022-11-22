/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:16:19 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/22 14:44:34 by nplieger         ###   ########.fr       */
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

void	ft_plus_convertor(const char *s, t_flags *flags_list, int *i)
{
	if (s[*i] == '+')
	{
		flags_list->plus = TRUE;
		(*i)++;
	}
}
