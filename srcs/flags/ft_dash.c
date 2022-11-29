/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 09:53:10 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/29 10:40:46 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_dash_setter(const char *s, t_flags *flags_list, int *i)
{
	if (s[*i] == '-')
	{
		flags_list->dash = TRUE;
		(*i)++;
	}
}

void	ft_dash_convertor(t_flags *flags)
{
	(void)flags;
}
