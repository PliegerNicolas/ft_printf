/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertor_dash.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 09:53:10 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/15 09:58:05 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_convertor_dash(const char *s, t_flags *flags_list, int *i)
{
	if (s[*i] == '-')
	{
		flags_list->dash = true;
		(*i)++;
	}
}
