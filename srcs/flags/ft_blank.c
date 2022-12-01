/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blank.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:15:22 by nplieger          #+#    #+#             */
/*   Updated: 2022/12/01 16:22:42 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_blank_setter(const char *s, t_flags *flags_list, int *i)
{
	if (s[*i] == ' ')
	{
		flags_list->blank = TRUE;
		(*i)++;
	}
}

void	ft_blank_convertor(t_flags *flags)
{
	if (flags->blank)
		ft_addprefix_to_positive(flags, " ");
}
