/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertor_hash.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:21:20 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/15 10:24:38 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_convertor_hash(const char *s, t_flags *flags_list, int *i)
{
	if (s[*i] == '#')
	{
		(*i)++;
		if (s[*i] == 'o')
		{
			flags_list->octal = true;
			(*i)++;
		}
		else if (s[*i] == 'x' || s[*i] == 'X')
		{
			flags_list->hex = true;
			(*i)++;
		}
		else if (s[*i] == 'e' || s[*i] == 'E' || s[*i] == 'f')
		{
			flags_list->decimal_point = true;
			(*i)++;
		}
		else if (s[*i] == 'g' || s[*i] == 'G')
		{
			flags_list->decimal_point_zeros = true;
			(*i)++;
		}
	}
}
