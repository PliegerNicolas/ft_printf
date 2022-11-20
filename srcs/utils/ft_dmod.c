/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dmod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 00:59:26 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/20 00:59:54 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

double	ft_dmod(double nb, int mod)
{
	unsigned long long int	ulli_nb;

	if (nb < 0)
		ulli_nb = -nb;
	else
		ulli_nb = nb;
	return ((double)(ulli_nb % mod));
}
