/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:08:41 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/16 13:38:49 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_digits_setter(const char *s, t_flags *flags_list, int *i)
{
	while (ft_isdigit(s[*i]))
	{
		flags_list->padding *= 10;
		flags_list->padding += s[(*i)++] - '0';
	}
}

void	ft_digits_convertor(const char *s, t_flags *flags_list, int *i)
{
	while (ft_isdigit(s[*i]))
	{
		flags_list->padding *= 10;
		flags_list->padding += s[(*i)++] - '0';
	}
}
