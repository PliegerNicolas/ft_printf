/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpadding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:08:31 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/14 17:47:13 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_putpadding(const char c, t_flags *flags_list)
{
	while (flags_list->padding > 0)
	{
		ft_putcharc(c, flags_list);
		flags_list->padding--;
	}
}
