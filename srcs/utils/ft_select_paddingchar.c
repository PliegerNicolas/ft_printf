/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_paddingchar.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:31:29 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/29 12:19:10 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

char	ft_select_paddingchar(t_flags *flags)
{
	char	paddingchar;

	if (flags->zero)
		paddingchar = '0';
	else
		paddingchar = ' ';
	return (paddingchar);
}
