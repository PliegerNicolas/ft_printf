/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:30:25 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/23 11:26:25 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_putstrc(const char *s, t_flags *flags_list, int *i)
{
	size_t		j;

	j = 0;
	while (s[j])
	{
		if (flags_list->dot && j == flags_list->dot_precision)
			break ;
		ft_putcharc(s[j++], flags_list);
	}
	if (flags_list->type == '\0')
		ft_putcharc('\0', flags_list);
	(*i)++;
}
