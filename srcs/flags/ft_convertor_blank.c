/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertor_blank.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:15:22 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/15 10:16:10 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_convertor_blank(const char *s, t_flags *flags_list, int *i)
{
	if (s[*i] == ' ')
	{
		flags_list->blank = true;
		(*i)++;
	}
}
