/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumeric.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:22:29 by nplieger          #+#    #+#             */
/*   Updated: 2022/12/01 09:53:19 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isnumeric(const char c)
{
	unsigned int	i;

	i = 0;
	while (TYPE_NUMERIC[i])
		if (c == TYPE_NUMERIC[i++])
			return (1);
	return (0);
}
