/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:30:25 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/14 13:35:13 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_putstrc(const char *s, t_flags *flags_list)
{
	while (*s)
	{
		flags_list->tw_chars += ft_putcharc(*s, flags_list);
		s++;
	}
}
