/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asterisk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 09:59:10 by nplieger          #+#    #+#             */
/*   Updated: 2022/12/15 13:51:44 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_asterisk_setter(const char *s, va_list args, t_flags *flags, int *i)
{
	if (s[*i] == '*' && flags->type)
	{
		flags->asterisk = TRUE;
		flags->max_width = va_arg(args, int);
		(*i)++;
	}
}

/*
void	ft_asterisk_convertor(t_flags *flags)
{
	(void)flags;
}
*/
