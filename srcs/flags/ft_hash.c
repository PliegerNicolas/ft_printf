/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:21:20 by nplieger          #+#    #+#             */
/*   Updated: 2022/12/01 17:07:07 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_hash_setter(const char *s, t_flags *flags_list, int *i)
{
	if (s[*i] == '#')
	{
		flags_list->hash = TRUE;
		(*i)++;
	}
}

void	ft_hash_convertor(t_flags *flags)
{
	if (flags->hash)
	{
		if (flags->type == 'x' && flags->str[0] != '0')
			ft_addprefix(flags, "0x");
		if (flags->type == 'X' && flags->str[0] != '0')
			ft_addprefix(flags, "0X");

	}
}
