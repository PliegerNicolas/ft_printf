/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:21:20 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/22 14:45:52 by nplieger         ###   ########.fr       */
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

void	ft_hash_convertor(const char *s, t_flags *flags_list, int *i)
{
	if (s[*i] == '#')
	{
		flags_list->hash = TRUE;
		(*i)++;
	}
}
