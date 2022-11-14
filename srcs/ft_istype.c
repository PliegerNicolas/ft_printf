/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_istype.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:22:29 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/14 09:25:41 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_istype(const char c)
{
	unsigned int	i;

	i = 0;
	while (TYPE_IDENTIFIERS[i])
		if (c == TYPE_IDENTIFIERS[i++])
			return (1);
	return (0);
}
