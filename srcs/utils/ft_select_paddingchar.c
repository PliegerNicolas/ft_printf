/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_paddingchar.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:31:29 by nplieger          #+#    #+#             */
/*   Updated: 2022/12/01 12:59:30 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

char	ft_select_paddingchar(t_flags *flags)
{
	char	paddingchar;

	if (*flags->str != '-' && flags->precision > flags->strlen)
		paddingchar = ' ';
	else if (flags->zero)
		paddingchar = '0';
	else
		paddingchar = ' ';
	return (paddingchar);
}
