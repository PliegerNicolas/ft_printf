/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillpadding.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:44:51 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/22 15:09:13 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_fillpadding(char	*s, size_t strlen, t_flags *flags_list)
{
	size_t	i;
	char	filler_char;

	if (flags_list->zero)
		filler_char = '0';
	else
		filler_char = ' ';
	i = 0;
	if (flags_list->dash)
		while (strlen < flags_list->padding)
			s[strlen++] = filler_char;
	else
		while (i < flags_list->padding - strlen)
			s[i++] = filler_char;
}
