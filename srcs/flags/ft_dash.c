/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 09:53:10 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/16 13:38:24 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_dash_setter(const char *s, t_flags *flags_list, int *i)
{
	if (s[*i] == '-')
	{
		flags_list->dash = true;
		(*i)++;
	}
}

void	ft_dash_convertor(const char *s, t_flags *flags_list, int *i)
{
	if (s[*i] == '-')
	{
		flags_list->dash = true;
		(*i)++;
	}
}
