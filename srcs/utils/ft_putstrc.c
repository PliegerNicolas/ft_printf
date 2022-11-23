/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:30:25 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/23 13:41:19 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_putstrc(const char *s, t_flags *flags_list, int *i)
{
	while (*s)
	{
		ft_putcharc(*s, flags_list);
		s++;
	}
	if (flags_list->type == '\0')
		ft_putcharc('\0', flags_list);
	(*i)++;
}
