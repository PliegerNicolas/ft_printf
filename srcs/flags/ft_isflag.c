/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isflag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:49:20 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/14 09:26:35 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_isflag(const char c)
{
	unsigned int	i;

	i = 0;
	while (FLAG_IDENTIFIERS[i])
		if (c == FLAG_IDENTIFIERS[i++])
			return (1);
	return (0);
}
